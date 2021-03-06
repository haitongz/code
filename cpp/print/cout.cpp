#include <iostream>
#include <iomanip>
#include <sstream>
int main()
{
  std::istringstream input(" \"Some text.\" ");
  volatile int n = 42;
  double f = 3.14;
  bool b = true;;
  int32_t u = 2147483658;
  std::cout << n   // int overload
    << ' ' // non-member overload
    << std::boolalpha << b // bool overload
    << " " // non-member overload
    << std::fixed << f // double overload
    << input.rdbuf() // streambuf overload
    << &n // bool overload
    << u
    << std::endl; // function overload
}
