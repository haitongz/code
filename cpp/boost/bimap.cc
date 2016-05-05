/*
 * test boost bimap
 * 双向映射
 */
#include <iostream>
#include <map>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/vector_of.hpp>

using namespace boost::bimaps;
using namespace boost;
using namespace std;

template<class T>
void print_map(T &m)
{
  BOOST_FOREACH(typename T::value_type v, m)
  {
    cout << v.first << " " << v.second << endl;
  }
}

typedef bimap<int, std::string> bm_t;

int main()
{
  std::map<int, int> test;
  test[1] = 2;
  test[1] = 4;
  cout << test[1] << endl;

  //bimap左值重复测试
  bm_t col;
  col.left.insert(make_pair(5, "hello"));
  //虽然无效，但是可以插入
  col.left.insert(make_pair(5, "world"));
  //测试显示的是第一次插入的值
  BOOST_AUTO(iter,col.left.find(5));
  cout << "left euql:" << iter->second << endl;

  //bimap 右值重复测试
  col.right.insert(make_pair("hello", 10));
  BOOST_AUTO(iter2, col.right.find("hello"));
  cout << "right euqal:" << iter2->second << endl;

}
