#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
typedef enum {Linux=1, Apple=2, Windows=4} OS_type;
int main ()
{
  std::string pi = "pi is " + std::to_string(3.1415926);
  std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";
  OS_type myOS = Windows;
  std::cout << std::to_string(myOS) << std::endl;

  std::cout << pi << '\n';
  std::cout << perfect << '\n';
  return 0;
}
