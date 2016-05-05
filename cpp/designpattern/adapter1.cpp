// 对象适配器
#include <stdlib.h>
#include <iostream>

class Target
{
public:
  virtual ~Target ()
  {

  }

  virtual void Request()
  {
    std::cout << "Target::Request" << std::endl;
  }
};

class Adaptee
{
public:
  virtual ~Adaptee ()
  {

  }

  void SpecificRequest()
  {
    std::cout << "Adaptee::SpecificRequest" << std::endl;
  }
};

class Adapter:public Target
{
public:
  Adapter (Adaptee* ade)
  {
    this->_ade = ade;
  }
  void Request()
  {
    _ade->SpecificRequest();
  }

private:
  Adaptee* _ade;
};

int main(int argc, char *argv[])
{
  Adaptee* ade = new Adaptee;
  Target* adt = new Adapter(ade);

  adt->Request();

  return 0;
}

//1. 当接口不同时，首先不应该考虑用适配器，而是应该考虑通过重构统一接口。
//2. 使用适配器模式是无奈之举，通常在软件开发后期或维护期再考虑使用。
