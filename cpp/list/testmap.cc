#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;
int main()
{
  typedef map<int, int> intmap;
  intmap int_map;
  map<std::string, intmap> str_map;

  for (int i=0; i<20; i++)
  {
      int_map.insert(make_pair(i, 10));
    if (i == 9)
    {
      str_map.insert(make_pair("iam10", int_map));
      int_map.clear();
    }
    if (i == 19)
    {
      str_map.insert(make_pair("iam20", int_map));
    }
  }

  for (map<std::string, intmap>::iterator iter = str_map.begin(); iter != str_map.end(); iter++)
  {
    std::cout << "str_map" << iter->first << "::";
    for (map<int, int>::iterator iter_int = iter->second.begin(); iter_int != iter->second.end(); iter_int++)
    {
      std::cout <<  iter_int->first << ":" << iter_int->second << std::endl;
    }
  }
}
