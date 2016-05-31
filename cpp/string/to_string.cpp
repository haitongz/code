#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <sys/time.h>
const int LOOP_COUNT = 10000000;
typedef enum {Linux=1, Apple=2, Windows=4} OS_type;
int main ()
{
  std::string pi = "pi is " + std::to_string(3.1415926);
  std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";
  OS_type myOS = Windows;
  std::cout << std::to_string(myOS) << std::endl;

  std::cout << pi << '\n';
  std::cout << perfect << '\n';

  std::string str = "123421421";
  struct timeval start, end;
  int32_t result;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    result = std::atoi(str.c_str());
  }
  gettimeofday(&end, NULL);
  std::cout << "atoi timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    result = std::stoi(str);
  }
  gettimeofday(&end, NULL);
  std::cout << "stoi timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;
  return 0;
}
