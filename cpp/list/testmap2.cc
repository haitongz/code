#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main()
{
  map<std::string, vector<int> > str_map;

  vector<int> vec_int;
  vec_int.push_back(1);
  vec_int.push_back(2);
  vec_int.push_back(3);
  str_map.insert(make_pair("iam20", vec_int));

  for (map<std::string, vector<int> >::iterator iter = str_map.begin(); iter != str_map.end(); iter++)
  {
    std::cout << "str_map" << iter->first << "::";
    for (vector<int>::iterator iter_int = iter->second.begin(); iter_int != iter->second.end(); iter_int++)
    {
      std::cout <<  *iter_int << std::endl;
    }
  }

  //str_map["iam20"].pop_back();

  map<std::string, vector<int> >::iterator iter = str_map.find("iam20");
  if (iter != str_map.end())
  {
    iter->second.erase(iter->second.begin());
  }

  for (map<std::string, vector<int> >::iterator iter = str_map.begin(); iter != str_map.end(); iter++)
  {
    std::cout << "str_map" << iter->first << "::";
    for (vector<int>::iterator iter_int = iter->second.begin(); iter_int != iter->second.end(); iter_int++)
    {
      std::cout <<  *iter_int << std::endl;
    }
  }
}
