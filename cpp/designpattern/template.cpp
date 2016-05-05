#include <iostream>
using namespace std;

class AbstractClass
{
public:
  void TemplateMethod()
  {
    PrimitiveOperation1();
    std::cout << "TemplateMethod" << std::endl;
    PrimitiveOperation2();
  }
private:
protected:
  virtual void PrimitiveOperation1()
  {
    std::cout << "Default Operation1" << std::endl;
  }
  virtual void PrimitiveOperation2()
  {
    std::cout << "Default Operation2" << std::endl;
  }
};

class ConcreteClassA : public AbstractClass
{
  protected:
    void PrimitiveOperation1()
    {
      std::cout << "ConcreteA Operation1" << std::endl;
    }
    void PrimitiveOperation2()
    {
      std::cout << "ConcreteA Operation2" << std::endl;
    }
};

class ConcreteClassB : public AbstractClass
{
  protected:
    void PrimitiveOperation1()
    {
      std::cout << "ConcreteB Operation1" << std::endl;
    }
    void PrimitiveOperation2()
    {
      std::cout << "ConcreteB Operation2" << std::endl;
    }
};

int main(int argc, char *argv[])
{
  AbstractClass *pAbstractA = new ConcreteClassA;
  pAbstractA->TemplateMethod();

  AbstractClass *pAbstractB = new ConcreteClassB;
  pAbstractB->TemplateMethod();

  if (pAbstractA) {
    delete pAbstractA;
  }
  if (pAbstractB) {
    delete pAbstractB;
  }
  return 0;
}


//在面向对象系统的分析与设计过程中经常会遇到这样一种情况：
//对于某一个业务逻辑（算法实现）在不同的对象中有不同的细节实现，
//但是逻辑（算法）的框架（或通用的应用算法）是相同的。Template提供了这种情况的一个实现框架。
//Template 模式是采用继承的方式实现这一点：将逻辑（算法）框架放在抽象基类中，
//并定义好细节的接口，子类中实现细节。



