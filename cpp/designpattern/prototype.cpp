#include <stdlib.h>
#include <iostream>

using namespace std;

class Prototype
{
public:
  virtual ~Prototype () {}
  virtual Prototype* Clone() const = 0;
};

class ConcretePrototype:public Prototype
{
  public:
    ConcretePrototype() {}

    ConcretePrototype(const ConcretePrototype& cp)
    {
      std::cout << "ConcretePrototype copy ..." << std::endl;
    }

    Prototype* Clone() const
    {
      return new ConcretePrototype(*this);
    }
};

int main(int argc, char *argv[])
{
  ConcretePrototype p1;
  ConcretePrototype p2 = p1;

  Prototype* p3 = new ConcretePrototype();
  Prototype* p4 = p3->Clone();

  return 0;
}
