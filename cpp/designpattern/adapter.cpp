// adapder 类适配器
#include <stdlib.h>
#include <iostream>

using namespace std;

// 目标类，可以想你成客户期待的接口
class Target
{
public:
  Target ()
  {

  }
  virtual ~Target ()
  {

  }
  virtual void Request()
  {
    std::cout << "Target::Request" << std::endl;
  }
};

// 被适应者，可以看成dll提供的接口
class Adaptee
{
public:
  Adaptee ()
  {

  }
  virtual ~Adaptee ()
  {

  }

  void SpecificRequest()
  {
    std::cout << "Adaptee::SepcificRequest" << std::endl;
  }

private:
};

// 适配器类，通过在内部包装被适应者对象adaptee
// 把源接口（specificRequest) 转换成目标接口（Request）
class Adapter: public Target, private Adaptee
{
  public:
    void Request()
    {
      this->SpecificRequest();
    }
};

int main(int argc, char *argv[])
{
  //Adaptee* ade = new Adaptee;
  Target* adt = new Adapter;
  adt->Request();

  return 0;
}


