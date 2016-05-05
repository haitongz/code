#include "boost/make_shared.hpp"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
  typedef std::vector<shared_ptr<int> > vs;
  vs v(10);
  int i = 0;
  for (vs::iterator pos = v.begin(); pos != v.end(); ++pos)
  {
    (*pos) = make_shared<int>(++i);
    cout << *(*pos) << ", ";
  }

  shared_ptr<int> p = v[9];
  *p = 100;
  cout << *v[9] << endl;
  return 0;
}
