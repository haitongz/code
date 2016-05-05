#include <iostream>
#include <map>
#include <algorithm>
#include <list>
using namespace std;

struct Node
{
  int key;
  int value;
};

class LRUCache
{
public:
  LRUCache (int capacity)
  {
    maxSize = capacity;
  }

  int get(int key)
  {
    std::map<int, list<Node>::iterator >::iterator it = mp.find(key);
    if (it == mp.end())
    {
      return -1;
    }
    else
    {
      list<Node>::iterator listIt = mp[key];
      Node newNode;
      newNode.key = key;
      newNode.value = listIt->value;
      cacheList.erase(listIt);
      cacheList.push_front(newNode);
      mp[key] = cacheList.begin();
    }
    return cacheList.begin()->value;
  }
   void set(int key, int value)
   {
     map<int, list<Node>::iterator >::iterator it = mp.find(key);
     if(it == mp.end())
     {
       if(cacheList.size() == maxSize)
       {
         mp.erase(cacheList.back().key);
         cacheList.pop_back();
       }
       Node newNode;
       newNode.key = key;
       newNode.value = value;
       cacheList.push_front(newNode);
       mp[key] = cacheList.begin();
     }
     else
     {
       list<Node>::iterator listIt = mp[key];
       cacheList.erase(listIt);
       Node newNode;
       newNode.key = key;
       newNode.value = value;
       cacheList.push_front(newNode);
       mp[key] = cacheList.begin();
     }
   }
private:
  int maxSize;
  list<Node> cacheList;
  map<int, list<Node>::iterator > mp;
};

int main(int argc, char *argv[])
{
  LRUCache cache(3);
  cache.set(1,1);
  cache.set(2,2);
  cache.set(3,3);
  cache.set(4,4);

  cout<<cache.get(4)<<endl;
  cout<<cache.get(3)<<endl;
  cout<<cache.get(2)<<endl;
  cout<<cache.get(1)<<endl;

  cache.set(5, 5);

  cout<<cache.get(1)<<endl;
  cout<<cache.get(2)<<endl;
  cout<<cache.get(3)<<endl;
  cout<<cache.get(4)<<endl;
  cout<<cache.get(5)<<endl;

  return 0;
}
