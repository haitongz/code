#include <iostream>
#include <cstring>

int main()
{
//  char *str = new char[100];
  char *str;
  str = (char *)malloc(10);
 // std::strcpy(str, "I am string!");
  //std::cout << str;
  std::string strsrc = "stringstringsssssssssssssssssss";
  std::strcpy(str, strsrc.c_str());
  std::cout << str;
  free(str);
}
