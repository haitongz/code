#include <stdio.h>
#include <string>
#include <exception>
#include <iostream>

int main(void) {
  char source[] = "hello, world!\1 welcome to china!\1";
  char delim[] = " ,!";

  std::string abc= std::string(source);
  char des[30]={0};
  memcpy(des, abc.c_str(), 30);
  printf(des);
  printf("\n");
  char *s = strdup(des);
  char *token;
  token = strsep(&s, "\1");
  printf(token);
  printf("\n");
  return 0;
}
//int strsepfun()
//{
  //char source[] = "hello, world!\1 welcome to china!\1";
  //char delim[] = " ,!";

  //std::string abc= std::string(source);
  //char des[30]={0};
  //memcpy(des, abc.c_str(), 30);
  //printf(des);
  //char *s = strdup(des);
  //char *token;
  //char *a = NULL;
  //token = strsep(&a, "\1");
  //printf(token);
  //return 0;
//}
//int main(void) {
  //try{
    //strsepfun();
  //}
  //catch (std::exception& e)
  //{
    //std::cout << "Standard exception: " << e.what() << std::endl;
  //}
  //return 0;
//}
