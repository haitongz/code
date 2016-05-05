#include <iostream>
using namespace std;

class Algorithm
{
  public:
    virtual void calculate() = 0;
};

class RSA_Algorithm : public Algorithm
{
  public:
    void calculate()
    {
      std::cout << "RSA_Algorithm ..." << std::endl;
    }
};


class DES_Algorithm : public Algorithm
{
  public:
    void calculate()
    {
      std::cout << "DES_Algorithm ..." << std::endl;
    }
};

class BASE64_Algorithm : public Algorithm
{
  public:
    void calculate()
    {
      std::cout << "BASE64_Algorithm ..." << std::endl;
    }
};

class Algorithm_Context
{
  private:
    Algorithm *m_ra;
  public:
    Algorithm_Context(Algorithm *ra)
    {
      m_ra = ra;
    }
    ~Algorithm_Context()
    {
      delete m_ra;
    }
    void calculate()
    {
      m_ra->calculate();
    }
};

int main(int argc, char *argv[])
{
  Algorithm_Context context(new RSA_Algorithm()); // 使用具体的算法
  context.calculate();

  return 0;
}

// 此程序的功能是评估几种加密算法时间，程序的使用操作不怎么变，变得是选用各种算法
// 它定义了算法家族，分别封装起来，让它们之间可以互相替换，此算法的变化，不会影响到使用算法的客户。
// 这里的关键就是将算法的逻辑抽象接口（DoAction）封装到一个类中（Context），
// 再通过委托的方式将具体的算法实现委托给具体的 Strategy 类来实现（ConcreteStrategeA类）。
