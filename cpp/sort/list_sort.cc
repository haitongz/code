#include <iostream>
#include <list>
#include <string>

using namespace std;

int main( void  )
{
  std::list<std::string> list;
  list.push_back("abc");
  list.push_back("c");
  list.push_back("abcd");
  list.push_back("ad");

  list.sort();

  for (std::list<std::string>::const_iterator i = list.begin(); i != list.end(); ++i) {
   std::cout << *i << std::endl;
  }
  return 0;

}
