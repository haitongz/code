#include <stdlib.h>
#include <iostream>
#include <list>

using namespace std;

// 公司类，提供接口
class Company
{
public:
  Company (string name)
  {
    m_name = name;
  }

  virtual ~Company ()
  { }

  virtual void Add (Company *pCom)
  { }

  virtual void Display (int depth)
  { }

private:
protected:
  string m_name;
};

// 具体公司
class ConcreteCompany:public Company
{
public:
  ConcreteCompany (string name): Company(name)
  { }
  virtual ~ConcreteCompany ()
  { }

  // add 子树或叶子
  void Add(Company *pCom)
  {
    m_listCompany.push_back(pCom);
  }

  void Display(int depth)
  {
    for (int i = 0; i < depth; ++i)
    {
      std::cout << "-";
    }
    std::cout << m_name << std::endl;
    list<Company *>::iterator iter = m_listCompany.begin();
    for (; iter != m_listCompany.end(); iter++)
    {
      (*iter)->Display(depth + 2);
    }
  }

private:
  list<Company *> m_listCompany;
};

//具体的部门，财务部
class FinanceDepartment : public Company
{
public:
  FinanceDepartment (string name) : Company(name)
  { }
  virtual ~FinanceDepartment ()
  { }

  virtual void Display(int depth)
  {
    for (int i = 0; i < depth; i++) {
      std::cout << "-";
    }
    std::cout << m_name << std::endl;
  }
};

//具体的部门，人力资源部
class HRDepartment : public Company
{
public:
  HRDepartment (string name):Company(name)
  { }
  virtual ~HRDepartment ()
  {

  }

  virtual void Display(int depth)
  {
    for (int i = 0; i < depth; i++) {
      std::cout << "-";
    }
    std::cout << m_name << std::endl;
  }
};

int main(int argc, char *argv[])
{
  Company *root = new ConcreteCompany("总公司");
  Company *leaf1 = new FinanceDepartment("财务部");
  Company *leaf2 = new HRDepartment("人力资源部");
  root->Add(leaf1);
  root->Add(leaf2);

  // 华东分公司
  Company *mid1 = new ConcreteCompany("华东分公司");
  Company *leaf3 = new FinanceDepartment("华东分公司财务部");
  Company *leaf4 = new ConcreteCompany("华东分公司人力资源部");
  mid1->Add(leaf3);
  mid1->Add(leaf4);
  root->Add(mid1);

  // 南京办事处
  Company *mid2 = new ConcreteCompany("南京办事处");
  FinanceDepartment *leaf5 = new FinanceDepartment("南京办事处财务部");
  HRDepartment *leaf6 = new HRDepartment("南京办事处人力资源部");
  mid2->Add(leaf5);
  mid2->Add(leaf6);
  mid1->Add(mid2);

  // 杭州办事处
  Company *mid3 = new ConcreteCompany("杭州办事处");
  FinanceDepartment *leaf7 = new FinanceDepartment("杭州办事处财务部");
  HRDepartment *leaf8 = new HRDepartment("杭州办事处人力资源部");
  mid3->Add(leaf7);
  mid3->Add(leaf8);
  mid1->Add(mid3);

  root->Display(0);

  delete leaf1;
  delete leaf2;
  delete leaf3;
  delete leaf4;
  delete leaf5;
  delete leaf6;
  delete leaf7;
  delete leaf8;

  delete mid1;
  delete mid2;
  delete mid3;
  delete root;

  return 0;
}
// 组合模式：将对象组合成树形结构以表示“部分-整体” 的层次结构。组合模式使得用户对单个对象和组合对象
// 的使用具有一致性。
//
// 组合模式将小对象组合成树形结构，使用户操作组合对象如同操作一个单个对象。组合模式定义了“部分-整体”
// 的层次结构，基本对象可以被组合成更大的对象，而且这种操作是可重复的，不断重复下去就可以得到一个非常
// 大的组合对象，但这些组合对象与基本对象拥有相同的接口，因而组合是透明的，用法完全一致。
//
// 我们可以这样简单的理解组合模式，组合模式就是把一些现有的对象或者元素，经过组合后组成新的对象。
// 新的对象提供内部方法，可以让我们很方便的完成这些元素或者内部对象的访问和操作。我们也可以把组合
// 对象理解成一个容器，容器提供各种访问其内部对象或者元素的API，我们只需要使用这些方法就可以操作它了。
// http://www.jellythink.com/archives/149
// http://blog.csdn.net/lwbeyond/article/details/7553422
// Composite模式和Decorator模式有着类似的结构图，但是Composite模式旨在构造类，而Decorator模式重在不生成
// 子类即可给对象添加职责。Decorator重在装饰，而Composite重在表示。

