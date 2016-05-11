#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <stdint.h>
#include "modp_b64.h"

using namespace std;
const int LOOP_COUNT = 100000;
// http://blog.csdn.net/morewindows/article/details/11871429
static const uint8_t kBase64DecodeTable[256] ={
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3e,0xff,0xff,0xff,0x3f,
0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,
0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0xff,0xff,0xff,0xff,0xff,
0xff,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,
0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,0x32,0x33,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
};
static const uint8_t *kBase64EncodeTable = (const uint8_t *)
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void  base64_encode(const uint8_t *in, uint32_t len, uint8_t *buf) {
  buf[0] = kBase64EncodeTable[(in[0] >> 2) & 0x3f];
  if (len == 3) {
    buf[1] = kBase64EncodeTable[((in[0] << 4) & 0x30) | ((in[1] >> 4) & 0x0f)];
    buf[2] = kBase64EncodeTable[((in[1] << 2) & 0x3c) | ((in[2] >> 6) & 0x03)];
    buf[3] = kBase64EncodeTable[in[2] & 0x3f];
  } else if (len == 2) {
    buf[1] = kBase64EncodeTable[((in[0] << 4) & 0x30) | ((in[1] >> 4) & 0x0f)];
    buf[2] = kBase64EncodeTable[(in[1] << 2) & 0x3c];
  } else  { // len == 1
    buf[1] = kBase64EncodeTable[(in[0] << 4) & 0x30];
  }
}
// original encode
std::string Base64Encode(const std::string& src, std::string ending = "")
{
  uint8_t i = 0;
  uint8_t b[4];
  const uint8_t *bytes = (const uint8_t *) src.c_str();
  uint32_t len = src.length();

  std::stringstream ss;

  while (len >= 3)
  {
    base64_encode(bytes, 3, b);
    for (i = 0; i < 4; i++)
      ss << b[i];
    bytes += 3;
    len -= 3;
  }

  if (len > 0)
  {
    base64_encode(bytes, len, b);
    for (i = 0; i < len + 1; i++)
      ss << b[i];
  }

  ss << ending;

  return ss.str();
}
// string 代替stringstream
std::string Base64Encode1(const std::string& src, std::string ending = "")
{
  uint8_t i = 0;
  uint8_t b[4];
  const uint8_t *bytes = (const uint8_t *) src.c_str();
  uint32_t len = src.length();

  std::string s;

  while (len >= 3)
  {
    base64_encode(bytes, 3, b);
    for (i = 0; i < 4; i++)
      s += b[i];
    bytes += 3;
    len -= 3;
  }

  if (len > 0)
  {
    base64_encode(bytes, len, b);
    for (i = 0; i < len + 1; i++)
      s += b[i];
  }

  s += ending;

  return s;
}
// string reserve
std::string Base64Encode2(const std::string& src, std::string ending = "")
{
  uint8_t i = 0;
  uint8_t b[4];
  const uint8_t *bytes = (const uint8_t *) src.c_str();
  uint32_t len = src.length();

  uint32_t encode_len = len << 2;
  std::string s;
  s.reserve(encode_len);

  while (len >= 3)
  {
    base64_encode(bytes, 3, b);
    for (i = 0; i < 4; i++)
      s += b[i];
    bytes += 3;
    len -= 3;
  }

  if (len > 0)
  {
    base64_encode(bytes, len, b);
    for (i = 0; i < len + 1; i++)
      s += b[i];
  }

  s += ending;

  return s;
}

// reinterpret_cast, range copy
std::string Base64Encode3(const std::string& src, std::string ending = "")
{
  uint8_t i = 0;
  uint8_t b[4];
  const uint8_t *bytes = (const uint8_t *) src.c_str();
  uint32_t len = src.length();

  std::string s;
  s.reserve(len*4/3 + 4);

  while (len >= 3)
  {
    base64_encode(bytes, 3, b);
    s.append(reinterpret_cast<char const*>(b),4);
    bytes += 3;
    len -= 3;
  }

  if (len)
  {
    base64_encode(bytes, len, b);
    s.append(reinterpret_cast<char const*>(b),len+1);
  }

  s += ending;

  return s;
}
// range copy 使用更大的初始数组，encode时数组下标移动,最后一起string copy
std::string Base64Encode4(const std::string& src, std::string ending = "")
{
  uint32_t i = 0;
  const uint8_t *bytes = (const uint8_t *) src.c_str();
  uint32_t len = src.length();

  std::string s;
  s.reserve(len/3*4 + 4);
  uint32_t encode_len = (len/3)*4;
  uint8_t c[encode_len];

  while (len >= 3)
  {
    base64_encode(bytes, 3, &c[i]);
    i += 4;
    bytes += 3;
    len -= 3;
  }
  if (encode_len)
  {
    s.append(reinterpret_cast<char const*>(c), encode_len);
  }

  uint8_t b[4];
  if (len > 0)
  {
    base64_encode(bytes, len, b);
    s.append(reinterpret_cast<char const*>(b),len+1);
  }

  s += ending;

  return s;
}

std::string Base64Encode5(const std::string& src, std::string ending = "")
{
  const uint8_t *bytes = (const uint8_t *) src.c_str();
  uint32_t len = src.length();

  std::string s((len+2)/3*4 + 1, '\0');
  char* c = const_cast<char *>(s.data());

  while (len >= 3)
  {
    base64_encode(bytes, 3, (uint8_t *)c);
    c += 4;
    bytes += 3;
    len -= 3;
  }

  if (len > 0)
  {
    base64_encode(bytes, len, (uint8_t *)c);
  }

  s += ending;

  return s;
}

bool Base64EncodeModp(const std::string& input, std::string* output)
{
  std::string temp;
  temp.resize(modp_b64_encode_len(input.size()));  // makes room for null byte

  // null terminates result since result is base64 text!
  int input_size = static_cast<int>(input.size());
  int output_size= modp_b64_encode(&(temp[0]), input.data(), input_size);
  if (output_size < 0)
    return false;

  temp.resize(output_size);  // strips off null byte
  output->swap(temp);
  return true;
}

int main(int argc, char *argv[])
{
  std::string s = "zqus387489tid'23	tck=e02fce03a933b5c8fffdf46442a2e8e9ts"
    "1461052882959uunid4tid=23&tck=e02fce03a933b5c8fffdf46442a2e8e9&ts=1461052882959&ver=1ip:106.39.88.82hostname:tf41dg.prod.mediav.comagent:Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4)"
    "AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.110 Safari/537.36lang:en,zh-CN;q=0.8,zh;q=0.6,zh-TW;q=0.4referer:http://ckmap.mediav.com/b?type=10proxy:106.39.88.82, 202.79.203.111_mvctn191270=_mvsrc=118216_523698_1043440&_mvcam=191270_1241961_11970810_58740969_0&osr=oqdT0qhmgzj0&time=1449650466&rdom=anonymous; _mvctn165564=_mvsrc=118478_524001_1044112&_mvcam=165564_1224948_11775153_58841999_0&osr=Zg4c0cS49V00&time=1451040575&rdom=anonymous; v=)he((]^XdqB2fOE=[AjT; _jzqa=1.4336274511317232000.1447337529.1447337529.1461045516.2; _jzqc=1; _jzqckmp=1; ckmts=PUPtXAzi,P6PtXAzi,RGPtXAzi,R6PtXAzi,U6PtXAzi,JGPtXAzi,JrPtXAzi,J6PtXAzi,bUPtXAziver10:0|0:0|0:0|0:10p!"
    "version1.01";
  s = s + s + s;
  //s = "MoreWindows - http://blog.csdn.net/morewindows?viewmode=contents ~!@#$%\r\n";
  //s = "ab";
  //std::string s = "zqus387489tid'23	tck=e02fce03a933b5c8fffdf46442a2e8e9tsaaa"
    //"1461052882959uunid4tid=23&tck=e02fce03a933b5c8fffdf46442a2e8e9&ts=1461052882959&ver=1ip:106.39.88.82hostname:tf41dg.prod.mediav.com";
  //std::string s = "zqus387489tid'23	tck=e02fce03a933b5c8fffdf46442a2e8e9ts1461052882959uunid4tid=23&tck=e02fce03a933b5c8fffdf46442a2e8e9&ts=1461052882959&ver=1ip:106.39.88.82hostname:tf41dg.prod.mediav.comaag";
  string a;
  struct timeval start, end;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    a = Base64Encode(s);
  }
  //std::cout << "base64encoded: " << a << std::endl;
  gettimeofday(&end, NULL);
  std::cout << "Base64Encode timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  string b;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    b = Base64Encode1(s);
  }
  //std::cout << "base64encoded: " << b << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " Base64Encode1 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  string e;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    e = Base64Encode2(s);
  }
  //std::cout << "base64encoded: " << e << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " Base64Encode2 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  string f;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    f = Base64Encode3(s);
  }
  //std::cout << "base64encoded: " << f << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " Base64Encode3 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  string g;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    g = Base64Encode4(s);
  }
  //std::cout << "base64encoded: " << g << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " Base64Encode4 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  string h;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    h = Base64Encode5(s);
  }
  //std::cout << "base64encoded: " << g << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " Base64Encode5 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  string c;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    Base64EncodeModp(s, &c);
  }
  //std::cout << "base64encoded: " << c << std::endl;
  gettimeofday(&end, NULL);
  std::cout << " Base64EncodeModp timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  if(a == b  && b == e && e == g && g == f)
  {
    std::cout << "They are same!!" << std::endl;
  }
  else
  {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "g: " << g << std::endl;
    std::cout << "h: " << h << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << a.length()
              << b.length()
              << e.length()
              << g.length()
              << h.length()
              << f.length();
  }
  return 0;
}
