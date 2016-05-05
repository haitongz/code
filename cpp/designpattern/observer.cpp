#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Subject;
// 观察者基类
class Observer
{
public:
  virtual ~Observer ()
  {
  }

  virtual void Update(Subject* sub) = 0;
  virtual void PrintInfo() = 0;

  Observer ()
  {
    _st = '\0';
  }
  string _st;
};

//////////////////////
//通知者基类
class Subject
{
public:
  virtual ~Subject()
  {
  }
  // 注册观察者 这样通知者就能通知到观察者
  virtual void Attach(Observer* obv)
  {
    _obvs->push_front(obv);
  }

  // 注销观察者，通知者不再通知观察者
  virtual void Detach(Observer* obv)
  {
    if (obv != NULL)
      _obvs->remove(obv);
  }

  // 通知操作，通知后对于每个注册过的观察者，将会调用自己的update方法
  virtual void Notify()
  {
    list<Observer*>::iterator it;
    it = _obvs->begin();

    for (;it != _obvs->end(); it++)
    {
      (*it)->Update(this);
    }
  }

  virtual void SetState(const string& st) = 0;
  virtual string GetState() = 0;

protected:
  Subject ()
  {
    _obvs = new list<Observer*>;
  }

private:
  list<Observer* >* _obvs;
};

// 具体的数据通知者
class DataSubject:public Subject
{
public:
  DataSubject ()
  {
    _st = '\0';
  }

  ~DataSubject()
  {
  }

  string GetState()
  {
    return _st;
  }

  void SetState(const string& st)
  {
    _st = st;
  }

private:
  string _st;
};

//数据表格观察者
class SheetObserver: public Observer
{
public:
  virtual Subject* GetSubject()
  {
    return _sub;
  }

  // 构造函数里，把自己注册到通知者里
  SheetObserver (Subject* sub)
  {
    _sub = sub;
    _sub->Attach(this);
  }

  virtual ~SheetObserver ()
  {
    _sub->Detach(this);
    if (_sub != 0)
      delete _sub;
  }

  // 更新操作
  void Update(Subject* sub)
  {
    _st = sub->GetState();
    PrintInfo();
  }

  void PrintInfo()
  {
    std::cout << "Sheet observer...." << _sub->GetState() << std::endl;
  }

private:
  Subject* _sub;
};

class ChatObserver:public Observer
{
public:
  ChatObserver (Subject* sub)
  {
    _sub = sub;
    _sub->Attach(this);
  }

  virtual ~ChatObserver ()
  {
    _sub->Detach(this);
    if (_sub != 0)
    {
      delete _sub;
    }
  }

  virtual Subject* GetSubject()
  {
    return _sub;
  }

  // 更新操作
  void Update(Subject* sub)
  {
    _st = sub->GetState();
    PrintInfo();
  }

  void PrintInfo()
  {
    std::cout << "Chat observer...." << _sub->GetState() << std::endl;
  }

private:
  Subject* _sub;
};


int main(int argc, char *argv[])
{
  DataSubject* sub = new DataSubject(); //数据通知者
  Observer* o1 = new SheetObserver(sub); //表格观察者
  Observer* o2 = new ChatObserver(sub); // 图表观察者

  sub->SetState("old data"); // 数据发生变化
  sub->Notify(); // 通知者下发通知

  sub->SetState("new data");
  sub->Notify();

  o1->Update(sub); // 也可以由观察者自己调用更新函数
  return 0;
}
