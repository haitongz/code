
#include <stdlib.h>
#include <iostream>

using namespace std;

class FileSys
{
public:
  virtual ~FileSys ()
  {
  }
  virtual void Operation()
  {
  }

protected:
  FileSys ()
  {
  }
};

class MyFileSys:public FileSys
{
public:
  MyFileSys ()
  {
  }
  ~MyFileSys ()
  {
  }
  void Operation()
  {
    std::cout << "MyFileSys Operation" << std::endl;
  }
};

class Decorator:public FileSys
{
public:
  Decorator (FileSys* file_sys)
  {
    this->_fileSys = file_sys;
  }
  virtual ~Decorator()
  {
    delete _fileSys;
  }
  void Operation()
  {

  }
protected:
  FileSys* _fileSys;
};

class ZipDecorator:public Decorator
{
public:
  ZipDecorator (FileSys* file_sys):Decorator(file_sys)
  {
  }
  ~ZipDecorator ()
  {
  }

  void Operation()
  {
    _fileSys->Operation();
    this->AddedZipBehavior();
  }

  void AddedZipBehavior()
  {
    std::cout << "AddedZipBehavior ..." << std::endl;
  }

};

//杀毒装饰类
class KillVirDecorator:public Decorator
{
public:
    KillVirDecorator(FileSys* fileSys):Decorator(fileSys)
    {
    }

    ~KillVirDecorator()
    {
    }

    void Operation()
    {
        _fileSys->Operation();

        this->AddedKillVirBehavior();
    }

    void AddedKillVirBehavior()
    {
        cout<<"Added Kill Virus Behavior...."<<endl;
    }
};

//加密装饰类
class EncryptDecorator:public Decorator
{
public:
    EncryptDecorator(FileSys* fileSys):Decorator(fileSys)
    {
    }

    ~EncryptDecorator()
    {
    }

    void Operation()
    {
        _fileSys->Operation();

        this->AddedEncrypeBehavior();
    }

    void AddedEncrypeBehavior()
    {
        cout<<"Added Encrypt Behavior...."<<endl;
    }
};

int main(int argc, char *argv[])
{
  FileSys* file_sys = new MyFileSys();

  Decorator* dec1 = new ZipDecorator(file_sys);  // add corpession feature
  Decorator* dec2 = new KillVirDecorator(dec1);      // add killVir feature
  Decorator* dec3 = new EncryptDecorator(dec2);      // add Encrpt feature

  dec3->Operation();
  return 0;
}
