#include <stdlib.h>
#include <iostream>

using namespace std;

class OS
{
  public:
    virtual void Run() {}
};

class WindowOS: public OS
{
  public:
    void Run()
    {
      std::cout << "Run Windows" << std::endl;
    }
};

class LinuxOS: public OS
{
  void Run()
  {
    std::cout << "Run Linux" << std::endl;
  }
};

class Computer
{
  public:
    virtual void InstallOS(OS *os) {}
};

class IBMComputer: public Computer
{
  public:
    void InstallOS(OS *os)
    {
      os->Run();
    }
};

class HPComputer: public Computer
{
  public:
    void InstallOS(OS *os)
    {
      os->Run();
    }
};

int main(int argc, char *argv[])
{
  OS *os1 = new WindowOS();
  OS *os2 = new LinuxOS();

  Computer *computer1 = new IBMComputer();
  computer1->InstallOS(os1);
  computer1->InstallOS(os2);

  return 0;
}
//定义：将抽象部分与它的实现部分分离，使它们都可以独立地变化。
//换句话出，就是要把实现独立出来，让它们各自变化，而不会影响其它实现，这样可以降低耦合性。
//为什么叫Bridge 模式，从上图中可以看出，它像一座桥，桥两边的系统相对独立，左边是抽象部分，右边是实现部分。
//尽量使用组合、聚合，尽量不要使用类继承。
