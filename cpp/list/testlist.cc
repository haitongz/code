#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct OO
{
  int a;
  double b;
};

int main()
{
  vector<OO> v;
  OO oo;
  oo.a = 1;
  oo.b = 2;
  v.push_back(oo);

  cout << "Address of data: &data = " << &oo << endl;
  cout << "Address of data in vector: &v[0] = " << &v[0] << endl;

  system("pause");
  return 0;
}
