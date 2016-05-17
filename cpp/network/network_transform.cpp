#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>

using namespace std;
const int LOOP_COUNT = 20000000;

uint32_t IpToInt(const string& ipStr)
{
  uint32_t result = 0;
  int segvalue = 0;
  basic_string<char>::size_type cur = 0;
  for (int i = 0; i < 4; i++)
  {
    segvalue = atoi(ipStr.substr(cur).c_str());
    if ((segvalue > 255) || (segvalue < 0))
    {
      return -1;
    }
    result += segvalue * (u_int32_t) (1 << ((3 - i) * 8));
    cur = ipStr.find(".", cur);
    if (cur == string::npos)
    {
      break;
    }
    cur++;
  }
  return result;
}

uint32_t IpToInt1(const string& ipStr)
{
  uint32_t result = 0;
  int segvalue = 0;
  basic_string<char>::size_type cur = 0;
  for (int i = 0; i < 4; i++)
  {
    segvalue = atoi(ipStr.substr(cur).c_str());
    if ((segvalue > 255) || (segvalue < 0))
    {
      return -1;
    }
    //result += segvalue * (u_int32_t) (1 << ((3 - i) * 8));
    result <<= 8;
    result |= segvalue & 0xff;
    cur = ipStr.find(".", cur);
    if (cur == string::npos)
    {
      break;
    }
    cur++;
  }
  return result;
}

u_int32_t IpToInt3(const char* pcIPStr)
{
  if (pcIPStr == NULL)
  {
    return -1;
  }
  u_int32_t result = 0;
  int segvalue = 0;
  char* cur = (char*) pcIPStr;
  for (int i = 0; i < 4;)
  {
    segvalue = atoi(cur);
    if ((segvalue > 255) || (segvalue < 0))
    {
      return -1;
    }
    result <<= 8;
    result |= segvalue & 0xff;
    i++;
    if (i == 4)
    {
      break;
    }
    cur = (char*) strchr(cur, '.');
    if (cur == NULL)
    {
      break;
    }
    cur++;
  }
  return result;
}

int32_t IpToInt2(const string& ipStr)
{
  return inet_network(ipStr.c_str());
}

int main(int argc, char *argv[])
{
  string ip_str = "192.168.3.233";
  //string ip_str = "127.0.0.1";

  struct timeval start, end;
  gettimeofday(&start, NULL);
  uint32_t result1;
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    result1 = IpToInt(ip_str);
  }
  gettimeofday(&end, NULL);
  std::cout << "iptoint timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;
  std::cout << result1 << std::endl;

  gettimeofday(&start, NULL);
  uint32_t result;
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    result = IpToInt1(ip_str);
  }
  gettimeofday(&end, NULL);
  std::cout << " iptoint1 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;
  std::cout << result << std::endl;

  gettimeofday(&start, NULL);
  uint32_t result2;
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    result2 = inet_network(ip_str.c_str());
  }
  gettimeofday(&end, NULL);
  std::cout << " iptoint2 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;
  std::cout << result2 << std::endl;

  gettimeofday(&start, NULL);
  uint32_t result3;
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    result3 = IpToInt3(ip_str.c_str());
  }
  gettimeofday(&end, NULL);
  std::cout << " iptoint3 timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;
  std::cout << result3 << std::endl;

  if (result == result1 && result1 == result2 && result2 == result3)
  {
    std::cout << IpToInt(ip_str) << std::endl;
  }
  else
  {
    std::cout << "different!!!" << std::endl;
  }
}
