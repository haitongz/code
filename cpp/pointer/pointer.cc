// my first pointer
#include <iostream>
using namespace std;

int main ()
{
  int firstvalue, secondvalue;
  int * mypointer;

  mypointer = &firstvalue;
  cout << "firstvalue address:" << mypointer << endl;
  *mypointer = 10;
  mypointer = &secondvalue;
  cout << "secondvalue address:" << mypointer << endl;
  *mypointer = 20;
  cout << "firstvalue is " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';
  return 0;
}
