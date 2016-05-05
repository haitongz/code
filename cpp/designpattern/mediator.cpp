#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Mediator;
class Country
{
  protected:
    Mediator *m_mediator;  // 中介
  public:
    virtual void SetMediator(Mediator *mediator) {} // 设置中介
    virtual void SendMessage(string message) {}     // 向中介发信息
    virtual void GetMessage(string message) {}      // 向中介获取信息
};


// 抽象中介者
class Mediator
{
  public:
    virtual void Send(string message, Country *person) {}
    virtual void SetJapan(Country *Japan) {} // 让中介认识具体的对象
    virtual void SetChina(Country *China) {}
};

// 日本
class Japan: public Country
{
  public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator;}
    void SendMessage(string message) { m_mediator->Send(message, this); }
    void GetMessage(string message) { std::cout << "日本收到消息：" << message;}
};
// 中国
class China: public Country
{
  public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator;}
    void SendMessage(string message) { m_mediator->Send(message, this); }
    void GetMessage(string message) { std::cout << "中国收到消息：" << message;}
};

// 联合国
class UN : public Mediator
{
  private:
    Country *m_Japan;
    Country *m_China;
  public:
    UN(): m_Japan(NULL), m_China(NULL) {}
    void SetJapan(Country *Japan) { m_Japan = Japan; }
    void SetChina(Country *China) { m_China = China; }
    void Send(string message, Country *country)
    {
      if (country == m_Japan)
        m_China->GetMessage(message);
      else
        m_Japan->GetMessage(message);
    }
};

int main(int argc, char *argv[])
{
  Mediator *mediator = new UN();
  Country *pJapan = new Japan();
  Country *pChina = new China();

  mediator->SetJapan(pJapan);
  mediator->SetChina(pChina);

  pJapan->SetMediator(mediator);
  pChina->SetMediator(mediator);

  pJapan->SendMessage("钓鱼岛是我们的，哈哈...\n");
  pChina->SendMessage("你放屁，小心我弄死你！ \n");

  delete pJapan;
  delete pChina;
  delete mediator;

  return 0;
}
