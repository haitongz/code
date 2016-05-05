/*
 * shared_ptr usage
 */

//shared_ptr<int> sp(new int(10));                //一个指向整数的shared_ptr
//assert(sp.unique());                            //现在shared_ptr是指针的唯一持有者
//shared_ptr<int> sp2 = sp;                       //第二个shared_ptr,拷贝构造函数
//assert(sp == sp2 && sp.use_count() == 2);		//两个shared_ptr相等,指向同一个对象,引用计数为2
//*sp2 = 100;										//使用解引用操作符修改被指对象
//assert(*sp == 100);								//另一个shared_ptr也同时被修改
//sp.reset();                                     //停止shared_ptr的使用
//assert(!sp);                                    //sp不再持有任何指针(空指针)
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
class Shared
{
  private:
    shared_ptr<int> p;
  public:
    Shared(shared_ptr<int> p_):p(p_){}
    void print()
    {
      cout << "count:" << p.use_count() << "v = " << *p << endl;
    }
};

void print_func(shared_ptr<int> p)  //shared_ptr copy
{
  cout << "count:" << p.use_count()
    << " v= " << *p << endl;
}

int main(int argc, char *argv[])
{
  shared_ptr<int> p(new int(100));
  Shared s1(p), s2(p);
  s1.print();
  s2.print();
  *p = 20;
  s2.print();
  print_func(p);
  s1.print();
  return 0;
}
