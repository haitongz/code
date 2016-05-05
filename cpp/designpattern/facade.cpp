#include <stdlib.h>
#include <iostream>

using namespace std;

class KillVirus
{
  public:
    void Operation1()
    {
      std::cout << "杀毒" << std::endl;
    }
};

class ZipFile
{
public:
  void Operation2()
  {
    std::cout << "压缩" << std::endl;
  }
};

class EncryptFile
{
public:
  void Operation3()
  {
    std::cout << "加密" << std::endl;
  }
};

class BurnCD
{
public:
  void Operation4()
  {
    std::cout << "记录" << std::endl;
  }
};

class OperatorWapper
{
public:
  void MethodA()
  {
    KillVirus kill;
    ZipFile zip;
    EncryptFile encrypt;
    BurnCD burn;

    kill.Operation1();
    zip.Operation2();
    encrypt.Operation3();
    burn.Operation4();
  }

  void MethodB()
  {
    KillVirus kill;
    BurnCD burn;

    kill.Operation1();
    burn.Operation4();
  }
};

int main(int argc, char *argv[])
{
  OperatorWapper op;
  op.MethodA(); // 完全功能
  op.MethodB(); // 简单功能

  return 0;
}

// 定义：为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，
// 这个接口使得这一子系统更加容易使用。简单得说就是分层的概念。
// 说明：
// 1. 在设计初期，应该有意识的将不同层分离，比如常用的三层架构 ，就是考虑在数据访问层，
// 业务逻辑层与表示层之间，建立Facade，使复杂的子系统提供一个简单的接口，降低耦合性。
// 2. 在开发阶段，子系统往往因为 不断的重构而变得越来越复杂，增加外观Facade可以提供一个简单的
// 接口，减少它们之间的依赖。
// 3. 在维护阶段，可能这个系统已经非常难以维护和扩展了，此时你可以为新系统开发一个外观类，来提供
// 设计粗糙或高度复杂的遗留代码的比较清晰简单的接口，让新系统与Facade对象交互，Facade与遗留代码交所有
// 复杂的工作。
//
