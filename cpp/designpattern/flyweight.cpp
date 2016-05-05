#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Flyweight
{
public:
  virtual ~Flyweight (){}
  virtual void Operation(const string& extrinsicState)
  {}
  string GetIntrinsicState()
  {
    return this->_intrinsicState;
  }
protected:
  Flyweight (string intrinsicState)
  {
    this->_intrinsicState = intrinsicState;
  }
private:
  string _intrinsicState;
};

class ConcreteFlyweight:public Flyweight
{
public:
  ConcreteFlyweight(string intrinsicState):Flyweight(intrinsicState)
  {
    std::cout << "ConcreteFlyweight Build ..." << intrinsicState << std::endl;
  }
  ~ConcreteFlyweight (){}
  void Operation(const string& extrinsicState)
  {
    std::cout << "内部" << this->GetIntrinsicState() << "] 外部[" << extrinsicState << "]" << std::endl;
  }
};

class FlyweightFactory
{
public:
  FlyweightFactory ()
  {}
  ~FlyweightFactory ();
  Flyweight* GetFlyweight(const string& key)
  {
    vector<Flyweight*>::iterator it = _fly.begin();
    for (; it != _fly.end(); it++)
    {
      if ((*it)->GetIntrinsicState() == key)
      {
        std::cout << "already created by users..." << std::endl;
        return *it;
      }
    }
    Flyweight* fn = new ConcreteFlyweight(key);
    _fly.push_back(fn);
    return fn;
  }

private:
  vector<Flyweight*> _fly;
};

int main(int argc, char *argv[])
{
  FlyweightFactory* fc = new FlyweightFactory();

  // 不同的对象 享元工厂将会创建新的元类
  Flyweight* fw1 = fc->GetFlyweight("Object A");
  fw1->Operation("extern object A");
  Flyweight* fw2 = fc->GetFlyweight("Object B");

  // 相同的对象，享元工厂将会使用一个已创建的享元类
  Flyweight* fw3 = fc->GetFlyweight("Object A");
  fw3->Operation("fw3 object A");

  return 0;
}
