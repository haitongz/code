#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>

//1.
template <typename Type> class QueueItem;

template <typename Type, int id, typename Info = std::string>
class Queue
{
  public:
    Queue(Info info):front_(NULL),last_(NULL),size_(0),info_(info),id_(id){}
    Type& Front();
    void Pop();
    void Push(const Type& val);
    bool IsEmpty()
    {
      return front_ == NULL;
    }
    size_t Size()
    {
      return size_;
    }
    Info& GetInfo()
    {
      return info_;
    }
    int GetId()
    {
      return id_;
    }
  private:
    QueueItem<Type> *front_;
    QueueItem<Type> *last_;
    size_t size_;
    Info info_;
    int id_;
};

template <typename Type> class QueueItem
{
  public:
    QueueItem(const Type& type):item(type),next_(NULL){}
    Type item;
    QueueItem<Type> *next_;
};

template <typename Type,int id, typename Info>
Type& Queue<Type,id,Info>::Front()
{
  return front_->item;
}

template <typename Type, int id, typename Info>
void Queue<Type, id, Info>::Pop()
{
  QueueItem<Type> *temp = front_;
  front_ = front_->next_;
  delete temp;
  --size_;
}

template <typename Type, int id, typename Info>
void Queue<Type, id, Info>::Push(const Type& val)
{
  QueueItem<Type> *p = new QueueItem<Type>(val);
  if (last_)
  {
    last_->next_ = p;
    last_ = last_->next_;
  }
  else
  {
    front_ = p;
    last_ = p;
  }
  ++size_;
}

int main(int argc, char *argv[])
{
  Queue<std::string,11>  q("first q");
  q.Push("hello");
  q.Push("world");
  q.Push("haitong");

  std::cout << q.Size() << std::endl;
  std::cout << q.GetInfo() << std::endl;
  std::cout << q.GetId() << std::endl;
  while(!q.IsEmpty())
  {
    std::string& str = q.Front();
    std::cout << str << std::endl;
    q.Pop();
  }
  Queue<std::string, 12> d("second d");
  d.Push("default");
  d.Push("Type");
  d.Push("is");
  d.Push("std::string");

  std::cout << d.Size() << std::endl;
  std::cout << d.GetInfo() << std::endl;
  std::cout << d.GetId() << std::endl;
  while(!d.IsEmpty())
  {
    std::string& str = d.Front();
    std::cout << str << std::endl;
    d.Pop();
  }

  return 0;

}
