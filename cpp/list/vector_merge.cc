#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
  std::vector<int> first;
  std::vector<int> second;
  for (int i=0; i<10; i++) first.push_back(i);
  for (int i=0; i<10; i++) second.push_back(i+1);
  first.insert(first.end(), second.begin(), second.end());
  for (std::vector<int>::const_iterator i = first.begin(); i != first.end(); ++i) {
    std::cout << *i << std::endl;
  }
  return 0;
}
