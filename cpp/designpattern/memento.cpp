#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

// 备忘录类
// 负责存储Ori
class Memento
{
  //注意：备忘录类中的方法是私有的
  private:
    // 这是最关键的地方，将Originator 为friend类
    // 这样Originator就可以访问Memento类的内部信息
    friend class Originator;
    Memento(){}
    Memento(const string& sdt)
    {
      _sdt = sdt;
    }

    void SetState(const string& sdt)
    {
      _sdt = sdt;
    }

    string GetState()
    {
      return _sdt;
    }

    string _sdt;
};

// 原始类
// 负责创建备忘录
class Originator
{
public:
  Originator ()
  {
    _sdt = "";
    _mt = 0;
  }

  Originator(const string& sdt)
  {
    _sdt = sdt;
    _mt = 0;
  }

  // 创建备忘录，将当前信息保存在一个备忘录对象中
  Memento* CreateMemento()
  {
    return new Memento(_sdt);
  }

  // 恢复备忘录，将备忘录对象上的信息恢复出来
  void RestoreToMemento(Memento* mt)
  {
    this->_sdt = mt->GetState();
  }

  string GetState()
  {
    return _sdt;
  }

  void SetState(const string& sdt)
  {
    _sdt = sdt;
  }

  void PrintState()
  {
    std::cout << this->_sdt << "....." << std::endl;
  }

private:
  string _sdt;
  Memento* _mt;
};

int main(int argc, char *argv[])
{
  Originator* o = new Originator();

  o->SetState("old"); // 备忘以前的状态
  o->PrintState();

  Memento* m = o->CreateMemento(); // 创建一个备忘录
  o->SetState("new"); // 修改状态
  o->PrintState();

  o->RestoreToMemento(m); // 恢复修改前的状态
  o->PrintState();

  return 0;
}
