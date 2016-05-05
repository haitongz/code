#include <stdlib.h>
#include <iostream>

using namespace std;
class Builder
{
public:
  virtual ~Builder ()
  {
  }

  virtual void BuildStep1() = 0;
  virtual void BuildStep2() = 0;
  virtual void BuildStep3() = 0;
  virtual void BuildStep4() = 0;
private:

};

class KFCBuilder:public Builder
{
public:
  void BuildStep1()
  {
    std::cout << "KFC Step1" << std::endl;
  }
  void BuildStep2()
  {
    std::cout << "KFC Step2" << std::endl;
  }
  void BuildStep3()
  {
    std::cout << "KFC Step3" << std::endl;
  }
  void BuildStep4()
  {
    std::cout << "KFC Step4" << std::endl;
  }
};
//Mcdonalds 具体建造者
class MCDBuilder:public Builder
{
public:
    void BuildSetp1()
    {
        cout<<"Mcdonalds Step1:"<<endl;
    }

    void BuildSetp2()
    {
        cout<<"Mcdonalds Step2:"<<endl;
    }

    void BuildSetp3()
    {
        cout<<"Mcdonalds Step3:"<<endl;
    }

    void BuildSetp4()
    {
        cout<<"Mcdonalds Step4:"<<endl;
    }

};

class Director
{
public:
  Director (Builder *builder)
  {
    m_pbuilder = builder;
  }
  void Create()
  {
    m_pbuilder->BuildStep1();
    m_pbuilder->BuildStep2();
    m_pbuilder->BuildStep3();
    m_pbuilder->BuildStep4();
  }

private:
  Builder *m_pbuilder;
};

int main(int argc,char* argv[])
{
    KFCBuilder kfc; //想吃KFC

    Director director(&kfc);
    director.Create();

    return 0;
}
