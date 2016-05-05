#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
// 虚基类
class BigImage
{
public:
  BigImage (string name): m_imageName(name)
  { }
  virtual ~BigImage ()
  { }
  virtual void Show()
  {}

protected:
  string m_imageName;
};
//真实类
class RealBigImage: public BigImage
{
public:
  RealBigImage (string name):BigImage(name)
  { }
  ~RealBigImage () {}

  void Show()
  {
    std::cout << "Show big image: " << m_imageName << std::endl;
  }
};

class Proxy: public BigImage
{
public:
  Proxy (string name):BigImage(name), m_bigImage(0)
  {}
  ~Proxy ()
  {
    delete m_bigImage;
  }

  void Show()
  {
    if(m_bigImage == NULL)
    {
      std::cout << "please wait ..." << std::endl;
      m_bigImage = new RealBigImage(m_imageName); //代理 创建真实对象
    }
    m_bigImage->Show();
  }

private:
  RealBigImage *m_bigImage;
};

int main(int argc, char *argv[])
{
  BigImage *image = new Proxy("SomeBig.jpg"); // 使用代理
  image->Show(); //代理的操作
  delete image;

  return 0;
}

// Proxy最大的好处是实现了逻辑和实现的彻底解耦
// 以下情况下可以考虑用Proxy模式解决问题：
// 1）解决开销大的对象时，比如显示一幅大图片，我们将这个创建的过程交给代理去完成，GOF称之为虚代理（Virtual Proxy）
// 2) 为网络上的对象创建一个局部本地代理，比如要操作一个网络上的一个对象（网络性能不好的时候，问题尤其突出）
//, 我们将这个操纵的过程交给一个代理去完成，GOF称之为远程代理（Remote Proxy）
// 3）对对象进行控制访问的时候，比如在论坛中不同权限的用户将获得不同层次的操作权限，我们将这个工作交给
// 一个代理去完成，GoF称之为保护代理（Protection Proxy）
// 4) 智能指针（smart Pointer）
