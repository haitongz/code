#include <iostream>
#include <list>
using namespace std;
class Seed;
class Status
{
public:
  virtual ~Status() {}
  virtual void VisitSeed_A(Seed* elm) {}
  virtual void VisitSeed_B(Seed* elm) {}
protected:
  Status() {}
};

//下雨状态
class Rain_Status:public Status
{
  public:
    Rain_Status() {}
    virtual ~Rain_Status() {}

    virtual void VisitSeed_A(Seed* elm)
    {
      std::cout << "Rain will visit Seed A..." << std::endl;
    }

    virtual void VisitSeed_B(Seed* elmA)
    {
      std::cout << "Rain will visit Seed B..." << std::endl;
    }
};

class Sun_Satus:public Status
{
  public:
    Sun_Satus() {}
    virtual ~Sun_Satus() {}

    virtual void VisitSeed_A(Seed* elm)
    {
      std::cout << "Sun will visit Seed A ..." << std::endl;
    }
    virtual void VisitSeed_B(Seed* elm)
    {
      std::cout << "Sun will visit Seed A ..." << std::endl;
    }
};

class Seed
{
public:
  virtual ~Seed() {}
  virtual void Accept(Status* vis) = 0;

protected:
  Seed() {}
};

// 种子A
class Seed_A:public Seed
{
  public:
    Seed_A() {}
    ~Seed_A(){}
    void Accept(Status* vis)
    {
      vis->VisitSeed_A(this);
    }
};

// 种子B
class Seed_B:public Seed
{
  public:
    Seed_B() {}
    ~Seed_B() {}

    void Accept(Status* vis)
    {
      vis->VisitSeed_B(this);
    }
};

// 对象结构类，为了对比不同种子
class ObjectStructure
{
  private:
    list<Seed*> lseed;

  public:
    void Attach(Seed* seed)
    {
      lseed.push_back(seed);
    }

    void Detach(Seed* seed)
    {
      lseed.remove(seed);
    }

    void Display(Status* status)
    {
      list<Seed*>::iterator it = lseed.begin();

      for (it; it != lseed.end(); ++it)
      {
        (*it)->Accept(status);
      }
    }
};

int main(int argc, char *argv[])
{
  ObjectStructure obj;

  // 加入 要对比两种种子
  obj.Attach(new Seed_A());
  obj.Attach(new Seed_B());

  // 查看各种状态下两个种子的情况
  obj.Display(new Rain_Status());
// Sun
  obj.Display(new Sun_Satus());

  return 0;
}



