
#include <stdlib.h>
#include <iostream>
#include <list>
using namespace std;

class Command;

// 实施与执行类
class Reciever
{
public:
  void Action()
  {
    std::cout << "Do action!!" << std::endl;
  }
};

// 抽象命令类
class Command
{
public:
  virtual ~Command()
  {
  }

  virtual void Excute() = 0;

protected:
  Command()
  {
  }
};

// Read命令
class Read_Command:public Command
{
public:
  Read_Command (Reciever* rev)
  {
    this->_rev = rev;
  }

  ~Read_Command()
  {
    delete this->_rev;
  }

  void Excute()
  {
    std::cout << "Read Command..." << std::endl;
    _rev->Action();
  }
private:
  Reciever* _rev;
};

// Write 命令
class Write_Command:public Command
{
public:
  Write_Command (Reciever* rev)
  {
    this->_rev = rev;
  }
  ~Write_Command()
  {
    delete this->_rev;
  }

  void Excute()
  {
    std::cout << "Write_Command..." << std::endl;
    _rev->Action();
  }

private:
  Reciever* _rev;
};

// 要求命令执行的类
class Invoker
{
public:
  Invoker (Command* cmd)
  {
    _cmd = cmd;
  }

  Invoker()
  {
  }
  ~Invoker ()
  {
    delete _cmd;
  }

  // 通知执行类执行
  void Notify()
  {
    list<Command*>::iterator it = cmdList.begin();

    for (it; it != cmdList.end(); ++it)
    {
      _cmd = *it;
      _cmd->Excute();
    }
  }

  // 添加命令
  void AddCmd(Command* pcmd)
  {
    cmdList.push_back(pcmd);
  }

  // 删除命令
  void DelCmd(Command* pcmd)
  {
    cmdList.remove(pcmd);
  }
private:
  Command* _cmd;
  list<Command*> cmdList;
};

int main(int argc, char *argv[])
{
  Reciever* rev = new Reciever(); // 定义一个执行类

  Command* cmd1 = new Read_Command(rev); // Read 命令
  Command* cmd2 = new Write_Command(rev); // Write 命令

  Invoker inv; // 管理所有命令

  inv.AddCmd(cmd1);
  inv.AddCmd(cmd2);
  inv.Notify();

  inv.DelCmd(cmd1);
  inv.Notify();

  return 0;
}
