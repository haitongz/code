#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <stdint.h>
#define STACK_ARRAY(TYPE, LEN) static_cast<TYPE*>(::alloca((LEN)*sizeof(TYPE)))
using namespace std;

const int LOOP_COUNT = 1;
const int LOOP_COUNT1 = 100000;

inline static char toHex(const char &x)
{
  return x > 9 ? x + 55: x + 48;
}
//原始线上代码
std::string UrlEncoding(const std::string &str_in, bool igore_percent_sign)
{
  std::stringstream str_buffer;
  for (size_t ix = 0; ix < str_in.size(); ix++)
  {
    char buf[4];
    memset(buf, 0, 4);
    if (isalnum((unsigned char) str_in[ix]))
    {
      buf[0] = str_in[ix];
    }
    else if (str_in[ix] == '_')
    {
      //FIXME remove enable_new_urlencode
      buf[0] = str_in[ix];
    }
    else if (isspace((unsigned char) str_in[ix]))
    {
      buf[0] = '+';
    }
    // if the url contains '%', we support it has been encoded. but maybe
    // wrong. like "%show"
    else if ( ((unsigned char) str_in[ix]) == '%' && igore_percent_sign)
    {
      buf[0] = str_in[ix];
    }
    else
    {
      buf[0] = '%';
      buf[1] = toHex((unsigned char) str_in[ix] >> 4);
      buf[2] = toHex((unsigned char) str_in[ix] % 16);
    }
    str_buffer << (char *) buf;
  }
  return str_buffer.str();
}
// original code
std::string UrlDecoding(const std::string &str_in)
{
  std::stringstream str_buffer;
  for (size_t ix = 0; ix < str_in.size(); ix++)
  {
    char ascii;
    char buf[3] = {0};
    if (isalnum(str_in[ix]))
    {
      ascii = str_in[ix];
    }
    else if ('+' == (str_in[ix]))
    {
      ascii = ' ';
    }
    // "%25"
    else if (str_in[ix] == '%' && ix + 2 < str_in.size() && isxdigit(str_in[ix + 1]) && isxdigit(str_in[ix + 2]))
    {
      buf[0] = str_in[ix + 1];
      buf[1] = str_in[ix + 2];
      ascii = strtol(buf, 0 , 16);
      ix += 2;
    }
    else // "%show"
    {
      ascii = str_in[ix];
    }
    str_buffer << ascii;
  }
  return str_buffer.str();
}

// string 基本优化
std::string UrlDecoding1(const std::string &str_in)
{
  std::string str_buffer;
  str_buffer.reserve(str_in.size());
  for (size_t ix = 0; ix < str_in.size(); ix++)
  {
    char buf[3] = {0};
    if (isalnum(str_in[ix]))
    {
      str_buffer += str_in[ix];
    }
    else if ('+' == (str_in[ix]))
    {
      str_buffer += ' ';
    }
    // "%25"
    else if (str_in[ix] == '%' && ix + 2 < str_in.size() && isxdigit(str_in[ix + 1]) && isxdigit(str_in[ix + 2]))
    {
      buf[0] = str_in[ix + 1];
      buf[1] = str_in[ix + 2];
      str_buffer += strtol(buf, 0 , 16);
      ix += 2;
    }
    else // "%show"
    {
      str_buffer += str_in[ix];
    }
  }
  return str_buffer;
}

// %处理优化
std::string UrlDecoding2(const std::string &str_in)
{
  std::string str_buffer;
  str_buffer.reserve(str_in.size());
  char buf[3] = {0};
  for (size_t ix = 0; ix < str_in.size(); ix++)
  {
    if (isalnum(str_in[ix]))
    {
      str_buffer += str_in[ix];
    }
    else if ('+' == (str_in[ix]))
    {
      str_buffer += ' ';
    }
    // "%25"
    else if (str_in[ix] == '%' && ix + 2 < str_in.size() && isxdigit(str_in[ix + 1]) && isxdigit(str_in[ix + 2]))
    {
      buf[0] = str_in[ix + 1];
      buf[1] = str_in[ix + 2];
      str_buffer += std::stoi(buf, 0, 16);
      ix += 2;
    }
    else // "%show"
    {
      str_buffer += str_in[ix];
    }
  }
  return str_buffer;
}

static int HexPairValue(const char * code) {
  int value = 0;
  const char * pch = code;
  for (;;) {
    int digit = *pch++;
    if (digit >= '0' && digit <= '9') {
      value += digit - '0';
    }
    else if (digit >= 'A' && digit <= 'F') {
      value += digit - 'A' + 10;
    }
    else if (digit >= 'a' && digit <= 'f') {
      value += digit - 'a' + 10;
    }
    else {
      return -1;
    }
    if (pch == code + 2)
      return value;
    value <<= 4;
  }
}
int InternalUrlDecode(const char *source, char *dest,
                      bool encode_space_as_plus) {
  char * start = dest;

  while (*source) {
    switch (*source) {
    case '+':
      if (encode_space_as_plus) {
        *(dest++) = ' ';
      } else {
        *dest++ = *source;
      }
      break;
    case '%':
      if (source[1] && source[2]) {
        int value = HexPairValue(source + 1);
        if (value >= 0) {
          *(dest++) = value;
          source += 2;
        }
        else {
          *dest++ = '?';
        }
      }
      else {
        *dest++ = '?';
      }
      break;
    default:
      *dest++ = *source;
    }
    source++;
  }

  *dest = 0;
  return static_cast<int>(dest - start);
}

std::string
InternalUrlDecodeString(const std::string & encoded,
                        bool encode_space_as_plus) {
  size_t needed_length = encoded.length() + 1;
  char* buf = STACK_ARRAY(char, needed_length);
  InternalUrlDecode(encoded.c_str(), buf, encode_space_as_plus);
  return buf;
}
std::string
InternalUrlDecodeString1(const std::string & encoded,
                        bool encode_space_as_plus) {
  size_t needed_length = encoded.length() + 1;
  char* buf = new char[needed_length]();
  InternalUrlDecode(encoded.c_str(), buf, encode_space_as_plus);
  std::string s(buf);
  delete buf;
  return s;
}

std::string
UrlDecodeString(const std::string & encoded) {
  return InternalUrlDecodeString(encoded, true);
}
std::string
UrlDecodeString2(const std::string & encoded) {
  return InternalUrlDecodeString1(encoded, true);
}

bool hex_decode(char ch, unsigned char* val)
{
  if ((ch >= '0') && (ch <= '9')) {
    *val = ch - '0';
  } else if ((ch >= 'A') && (ch <= 'Z')) {
    *val = (ch - 'A') + 10;
  } else if ((ch >= 'a') && (ch <= 'z')) {
    *val = (ch - 'a') + 10;
  } else {
    return false;
  }
  return true;
}

size_t url_decode(char * buffer, size_t buflen, const char * source, size_t srclen)
{
  if (NULL == buffer)
    return srclen + 1;
  if (buflen <= 0)
    return 0;

  unsigned char h1, h2;
  size_t srcpos = 0, bufpos = 0;
  while ((srcpos < srclen) && (bufpos + 1 < buflen)) {
    unsigned char ch = source[srcpos++];
    if (ch == '+') {
      buffer[bufpos++] = ' ';
    } else if ((ch == '%')
               && (srcpos + 1 < srclen)
               && hex_decode(source[srcpos], &h1)
               && hex_decode(source[srcpos+1], &h2))
    {
      buffer[bufpos++] = (h1 << 4) | h2;
      srcpos += 2;
    } else {
      buffer[bufpos++] = ch;
    }
  }
  buffer[bufpos] = '\0';
  return bufpos;
}

// Apply any suitable string transform (including the ones above) to an STL
// string.  Stack-allocated temporary space is used for the transformation,
// so value and source may refer to the same string.
typedef size_t (*Transform)(char * buffer, size_t buflen,
                            const char * source, size_t srclen);
//size_t transform(std::string& value, size_t maxlen, const std::string& source,
                 //Transform t);

//// Return the result of applying transform t to source.
//std::string s_transform(const std::string& source, Transform t);

//size_t transform(std::string& value, size_t maxlen, const std::string& source,
                 //Transform t) {
  //char* buffer = STACK_ARRAY(char, maxlen + 1);
  //size_t length = t(buffer, maxlen + 1, source.data(), source.length());
  //value.assign(buffer, length);
  //return length;
//}

std::string s_transform(const std::string& source, Transform t) {
  // Ask transformation function to approximate the destination size (returns upper bound)
  size_t maxlen = t(NULL, 0, source.data(), source.length());
  char * buffer = STACK_ARRAY(char, maxlen);
  size_t len = t(buffer, maxlen, source.data(), source.length());
  std::string result(buffer, len);
  return result;
}

// Convenience wrappers
inline std::string s_url_decode(const std::string& source) {
  return s_transform(source, url_decode);
}

int main ()
{
  //std::string s = "http://mediav.com/?arg1=abc 效 &type=1&x=http://xx.xx";
  std::string s = "http://is122ss.prod.mediav.com:8000/s?type=2&r=20&impid=bbfXLwMPwdI=&as=6&pf=TUUUUUUUUUU=&so=4&cus=174156_1127738_10970148_51447830_0&ctype=15&pinfo=&pub=116668_521691_1038920&mvid=MTA3MjQ2NzEzNTMxNDE5MjkwNDAwMTY&mv_ref=hao%2E360%2Ecn&enup=CAABynjgCggAAgrgeMoA&bidid=104ec3ab45e1eac9&price=AAAAAFcjQi0AAAAAAAHLbVAuonRYLa6DbHeabg==&finfo=DAABCAABAAAABQgAAgAAACMEAAM/HvWbW/E0UQAIAAIAAAADCgADhb/D/mokM28IAAQAAAApBgAGHxUIAAgAAMNQCgAJAAAAAAAAAIgGAAoAAAgACwAFfkAA&ugi=FfieDhW21z9MFQIVsgQVABUAAAA&uai=FZDpfiUCFQIW78vF+Ouz9MD0AQA&ubi=FZihFRX01IkBFciQuwoVrKCIMRUIFR4WiMqskwEW78u20LGAnsD0ATQMFpACFpC0ya8OAA&clickid=0&url=http%3A%2F%2Fwww%2Emeilele%2Ecom%2Fspecial%2F201510%2D1140%2Ehtml%23se%3Dqc%21XKJ%2D%21QDA7E588BFE68%21H%2D%21QBA2E594ADE8BF83E4B480E99%21H%2D3%21QAA7E7B%21H%21X%21QA8AE5B%21H2%2DJ10%2D%21X%21QE9EE5ACA8E69A8AE5B4A7E5A4A9E79D96E58%21H";
  std::cout << "encode_url: " << s << std::endl;

  string r1, r2, r3, r4, r5, r6;
  struct timeval start, end;
  gettimeofday(&start, NULL);
  string encoded_url;
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    encoded_url = UrlEncoding(s, false);
  }
  std::cout << encoded_url << std::endl;
  gettimeofday(&end, NULL);
  std::cout << "url_encode timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;
  s = encoded_url;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT1; ++i)
  {
    r1 = UrlDecoding(s);
  }
  gettimeofday(&end, NULL);
  std::cout << "url_decode timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT1; ++i)
  {
    r2 = UrlDecoding1(s);
  }
  gettimeofday(&end, NULL);
  std::cout << "url_decode1 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT1; ++i)
  {
    r3 = UrlDecodeString(s);
  }
  gettimeofday(&end, NULL);
  std::cout << "url_decode2 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT1; ++i)
  {
    r4 = UrlDecodeString2(s);
  }
  gettimeofday(&end, NULL);
  std::cout << "url_decode3 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT1; ++i)
  {
    r5 = s_url_decode(s);
  }
  gettimeofday(&end, NULL);
  std::cout << "url_decode4 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  if (r1 == r2 && r2 == r3 && r3 == r4 && r4 == r5)
  {
    std::cout << "result same!!!"  << std::endl;
  }
  else
  {
    std::cout << "They are diff!!!" << std::endl;
  }
  return 0;
}
