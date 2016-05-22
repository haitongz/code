#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <stdint.h>
#include <cassert>

#define STACK_ARRAY(TYPE, LEN) static_cast<TYPE*>(::alloca((LEN)*sizeof(TYPE)))
//url编码的主要内容是: 0-9A-Za-z以及-, ~, ., ~无需通过编码即可传输(普通字符), 而以下字符(保留字符):
//! * ‘ ( ) ; : @ & = + $ , / ? # [ ]
//如果要当作字符常量对待则需要经过编码. 另外其他的字符都需要进过url编码来进行传输.
//空格" "被转换为加号"+"。
//其他每个字节都被表示成"%xy"格式的由3个字符组成的字符串，编码为UTF-8。
//编码形式是%后跟对应的十六进制形式.
//https://en.wikipedia.org/wiki/Percent-encoding
using namespace std;

const int LOOP_COUNT = 100000;

inline static char toHex(const char &x)
{
  return x > 9 ? x + 55: x + 48;
}

static const uint32_t   uri_component[] = {
  0xffffffff, /* 1111 1111 1111 1111  1111 1111 1111 1111 */

              /* ?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
  0xfc00dffe, /* 1111 1100 0000 0000  1101 1111 1111 1110 */

              /* _^]\ [ZYX WVUT SRQP  ONML KJIH GFED CBA@ */
  0x78000001, /* 0111 1000 0000 0000  0000 0000 0000 0001 */

              /*  ~}| {zyx wvut srqp  onml kjih gfed cba` */
  0xb8000001, /* 1011 1000 0000 0000  0000 0000 0000 0001 */

  0xffffffff, /* 1111 1111 1111 1111  1111 1111 1111 1111 */
  0xffffffff, /* 1111 1111 1111 1111  1111 1111 1111 1111 */
  0xffffffff, /* 1111 1111 1111 1111  1111 1111 1111 1111 */
  0xffffffff  /* 1111 1111 1111 1111  1111 1111 1111 1111 */
  };

static const unsigned char   hex2[] = "0123456789ABCDEF";

// nginx url encode: http://blog.aka-cool.net/blog/2013/07/09/url-encode-in-nginx
std::string url_encode(const std::string &str_in)
{
  static unsigned char   hex[] = "0123456789ABCDEF";

  /* " ", "#", "%", "?", %00-%1F, %7F-%FF */

  /* 位图法判断是否需要进行编码 */

  std::string str_buffer;
  str_buffer.reserve(str_in.size() << 1);
for (size_t ix = 0; ix < str_in.size(); ix++)
{
  char buf[4];
  memset(buf, 0, 4);
  if (uri_component[(unsigned char) str_in[ix] >> 5] & (1 << ((unsigned char) str_in[ix] & 0x1f)))
  {
    buf[0] = '%';
    buf[1] = hex[(unsigned char) str_in[ix] >> 4];// ascii bit位用16进行表示
    buf[2] = hex[(unsigned char) str_in[ix] & 0xf];
  }
  else if (isspace((unsigned char) str_in[ix]))
  {
    buf[0] = '+';
  }
  else
  {
    buf[0] = str_in[ix];
  }
  str_buffer.append(buf);
}
return str_buffer;
}

//参考ngx_url_encoding, 主要是使用了位图来巧妙得查询一个字符是否需要encode
std::string url_encode2(const std::string &str_in)
{
  static unsigned char hex[] = "0123456789ABCDEF";

  std::string str_buffer;
  for (size_t ix = 0; ix < str_in.size(); ix++)
  {
    unsigned char x = str_in[ix];
    if (uri_component[x >> 5] & (1 << (x & 0x1f)))
    {
      str_buffer += '%';
      str_buffer += hex[x >> 4];
      str_buffer += hex[x & 0xf];
    }
    else if (isspace(x))
    {
      str_buffer += '+';
    }
    else
    {
      str_buffer += x;
    }
  }
  return str_buffer;
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
// 使用string 代替stringstream
std::string UrlEncoding2(const std::string &str_in, bool igore_percent_sign)
{
  std::string str_buffer;
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
    str_buffer.append(buf);
  }
  return str_buffer;
}
// 使用string+=代替char数组操作
std::string UrlEncoding3(const std::string &str_in, bool igore_percent_sign)
{
  static unsigned char hex[] = "0123456789ABCDEF";
  std::string str_buffer;
  for (size_t ix = 0; ix < str_in.size(); ix++)
  {
    if (isalnum((unsigned char) str_in[ix]))
    {
      str_buffer += str_in[ix];
    }
    else if (str_in[ix] == '_')
    {
      //FIXME remove enable_new_urlencode
      str_buffer += str_in[ix];
    }
    else if (isspace((unsigned char) str_in[ix]))
    {
      str_buffer += '+';
    }
     //if the url contains '%', we support it has been encoded. but maybe
     //wrong. like "%show"
    else if ( ((unsigned char) str_in[ix]) == '%' && igore_percent_sign)
    {
      str_buffer += str_in[ix];
    }
    else
    {
      str_buffer += '%';
      str_buffer += hex[(unsigned char) str_in[ix] >> 4];
      str_buffer += hex[(unsigned char) str_in[ix] & 0xf];
    }
  }
  return str_buffer;
}
//提前申请string的大小，避免string内存重新分配造成的内存copy
std::string UrlEncoding4(const std::string &str_in, bool igore_percent_sign)
{
  static unsigned char hex[] = "0123456789ABCDEF";
  std::string str_buffer;
  str_buffer.reserve(str_in.size() << 1);
  for (size_t ix = 0; ix < str_in.size(); ix++)
  {
    if (isalnum((unsigned char) str_in[ix]))
    {
      str_buffer += str_in[ix];
    }
    else if (str_in[ix] == '_')
    {
      //FIXME remove enable_new_urlencode
      str_buffer += str_in[ix];
    }
    else if (isspace((unsigned char) str_in[ix]))
    {
      str_buffer += '+';
    }
     //if the url contains '%', we support it has been encoded. but maybe
     //wrong. like "%show"
    else if ( ((unsigned char) str_in[ix]) == '%' && igore_percent_sign)
    {
      str_buffer += str_in[ix];
    }
    else
    {
      str_buffer += '%';
      str_buffer += hex[(unsigned char) str_in[ix] >> 4];
      str_buffer += hex[(unsigned char) str_in[ix] & 0xf];
    }
  }
  return str_buffer;
}

// chromimum
const unsigned char URL_UNSAFE  = 0x1; // 0-33 "#$%&+,/:;<=>?@[\]^`{|} 127
const unsigned char XML_UNSAFE  = 0x2; // "&'<>
const unsigned char HTML_UNSAFE = 0x2; // "&'<>

//  ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 6 5 7 8 9 : ; < = > ?
//@ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _
//` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~

const unsigned char ASCII_CLASS[128] = {
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  0,0,3,1,1,1,3,2,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,3,1,3,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,
};
static const char HEX[] = "0123456789ABCDEF";
char hex_encode(unsigned char val) {
  assert(val < 16);
  return (val < 16) ? HEX[val] : '!';
}

size_t url_encode(char * buffer, size_t buflen,
                  const char * source, size_t srclen) {
  if (NULL == buffer)
    return srclen * 3 + 1;
  if (buflen <= 0)
    return 0;

  size_t srcpos = 0, bufpos = 0;
  while ((srcpos < srclen) && (bufpos + 1 < buflen)) {
    unsigned char ch = source[srcpos++];

    if ((ASCII_CLASS[ch] & URL_UNSAFE)) {
      if (bufpos + 3 >= buflen) {
        break;
      }
      buffer[bufpos+0] = '%';
      buffer[bufpos+1] = hex_encode((ch >> 4) & 0xF);
      buffer[bufpos+2] = hex_encode((ch     ) & 0xF);
      bufpos += 3;
    } else if (isspace(ch))
    {
      buffer[bufpos++] = '+';
    }
    else {
      buffer[bufpos++] = ch;
    }
  }
  buffer[bufpos] = '\0';
  return bufpos;
}


typedef size_t (*Transform)(char * buffer, size_t buflen, const char * source, size_t srclen);
size_t transform(std::string& value, size_t maxlen, const std::string& source,
                 Transform t) {
  char* buffer = STACK_ARRAY(char, maxlen + 1);
  size_t length = t(buffer, maxlen + 1, source.data(), source.length());
  value.assign(buffer, length);
  return length;
}

std::string s_transform(const std::string& source, Transform t) {
  // Ask transformation function to approximate the destination size (returns upper bound)
  size_t maxlen = t(NULL, 0, source.data(), source.length());
  char * buffer = STACK_ARRAY(char, maxlen);
  size_t len = t(buffer, maxlen, source.data(), source.length());
  std::string result(buffer, len);
  return result;

}

inline std::string s_url_encode(const std::string& source) {
  return s_transform(source, url_encode);
}

// chromium 2
bool IsValidUrlChar(char ch, bool unsafe_only) {
  if (unsafe_only) {
    return !(ch <= ' ' || strchr("\\\"^&`<>[]{}", ch));
  } else {
    return isalnum(ch) || strchr("-_!~*'()", ch);
  }
}
int InternalUrlEncode(const char *source, char *dest, unsigned int max,
                      bool encode_space_as_plus, bool unsafe_only) {
  static const char *digits = "0123456789ABCDEF";
  if (max == 0) {
    return 0;
  }

  char *start = dest;
  while (static_cast<unsigned>(dest - start) < max && *source) {
    unsigned char ch = static_cast<unsigned char>(*source);
    if (*source == ' ' && encode_space_as_plus && !unsafe_only) {
      *dest++ = '+';
    } else if (IsValidUrlChar(ch, unsafe_only)) {
      *dest++ = *source;
    } else {
      if (static_cast<unsigned>(dest - start) + 4 > max) {
        break;
      }
      *dest++ = '%';
      *dest++ = digits[(ch >> 4) & 0x0F];
      *dest++ = digits[       ch & 0x0F];
    }
    source++;
  }
  assert(static_cast<unsigned int>(dest - start) < max);
  *dest = 0;

  return static_cast<int>(dest - start);
}
std::string
InternalUrlEncodeString(const std::string & decoded,
                        bool encode_space_as_plus,
                        bool unsafe_only) {
  int needed_length = static_cast<int>(decoded.length()) * 3 + 1;
  char* buf = STACK_ARRAY(char, needed_length);
  InternalUrlEncode(decoded.c_str(), buf, needed_length,
                    encode_space_as_plus, unsafe_only);
  return buf;
}
std::string
UrlEncodeString(const std::string & decoded) {
  return InternalUrlEncodeString(decoded, true, false);
}


int main ()
{
  //std::string s = "http://mediav.com/?arg1=abc 效 &type=1&x=http://xx.xx";
  //std::string s = "效";
  std::string s = "http://is122ss.prod.mediav.com:8000/s?type=2&r=20&impid=bbfXLwMPwdI=&as=6&pf=TUUUUUUUUUU=&so=4&cus=174156_1127738_10970148_51447830_0&ctype=15&pinfo=&pub=116668_521691_1038920&mvid=MTA3MjQ2NzEzNTMxNDE5MjkwNDAwMTY&mv_ref=hao%2E360%2Ecn&enup=CAABynjgCggAAgrgeMoA&bidid=104ec3ab45e1eac9&price=AAAAAFcjQi0AAAAAAAHLbVAuonRYLa6DbHeabg==&finfo=DAABCAABAAAABQgAAgAAACMEAAM/HvWbW/E0UQAIAAIAAAADCgADhb/D/mokM28IAAQAAAApBgAGHxUIAAgAAMNQCgAJAAAAAAAAAIgGAAoAAAgACwAFfkAA&ugi=FfieDhW21z9MFQIVsgQVABUAAAA&uai=FZDpfiUCFQIW78vF+Ouz9MD0AQA&ubi=FZihFRX01IkBFciQuwoVrKCIMRUIFR4WiMqskwEW78u20LGAnsD0ATQMFpACFpC0ya8OAA&clickid=0&url=http%3A%2F%2Fwww%2Emeilele%2Ecom%2Fspecial%2F201510%2D1140%2Ehtml%23se%3Dqc%21XKJ%2D%21QDA7E588BFE68%21H%2D%21QBA2E594ADE8BF83E4B480E99%21H%2D3%21QAA7E7B%21H%21X%21QA8AE5B%21H2%2DJ10%2D%21X%21QE9EE5ACA8E69A8AE5B4A7E5A4A9E79D96E58%21H";
  std::cout << "encode_url: " << s << std::endl;

  struct timeval start, end;
  gettimeofday(&start, NULL);
  string encoded_url;
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    encoded_url = url_encode2(s);
  }
  std::cout << encoded_url << std::endl;
  gettimeofday(&end, NULL);
  std::cout << "url_encode timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    encoded_url = UrlEncoding(s, false);
  }
  std::cout << encoded_url << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " UrlEncoding timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    encoded_url = UrlEncoding2(s, false);
  }
  std::cout << encoded_url << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " UrlEncoding2 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    encoded_url = UrlEncoding3(s, false);
  }
  std::cout << encoded_url << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " UrlEncoding3 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    encoded_url = UrlEncoding4(s, false);
  }
  std::cout << encoded_url << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " UrlEncoding4 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    encoded_url = UrlEncodeString(s);
  }
  std::cout << encoded_url << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " UrlEncoding5 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;
  return 0;
}
