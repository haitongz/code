#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>

using namespace std;
const int LOOP_COUNT = 1000000;

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

uint32_t IpToInt2(const string& ipStr)
{
  return inet_network(ipStr.c_str());
}

int main(int argc, char *argv[])
{
  char str[]="255.255.255.254";
  in_addr_t r1,r2,r3;
  struct in_addr inp;
  r1=inet_addr(str);
  if(r1==-1){
    printf("inet_addr return -1 when 255.255.255.255\n");
  }else{
    printf("inet_addr:ip=%lu\n",ntohl(r1));
    printf("inet_addr:ip=%lu\n",r1);
  }
  r2=inet_network(str);
  if(r2==-1){
    printf("inet_network return -1 when 255.255.255.255\n");
  }else{
    printf("inet_network:ip=%lu\n",r2);
  }
  r3=inet_aton(str,&inp);
  if(r3==0){
    printf("inet_aton return -1 when 255.255.255.255\n");
  }else{
    printf("inet_aton:ip=%lu\n",ntohl(inp.s_addr));
    printf("inet_aton:ip=%lu\n",inp.s_addr);
  }
  return 0;
}
