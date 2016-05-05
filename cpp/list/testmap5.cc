#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;
const static string ABC = "abc";
int main()
{
  typedef map<string, int> intmap;
  intmap int_map;
  int_map[ABC] = 123;
  std::cout << int_map[ABC] << std::endl;
}

