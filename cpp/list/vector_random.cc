#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

int myrandom (int i) { return std::rand()%i;}
int main()
{
    //std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::vector<int> v;
  for (int i=1; i<110; ++i) v.push_back(i);
    //std::random_device rd;
    //std::mt19937 g(rd());
  //  srand(time(NULL));

  std::srand ( unsigned ( std::time(0) ) );
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
      std::cout << *i << std::endl;
      if (*i == 3)
      {
        std::random_shuffle(i+1, v.end(), myrandom);
      }
    }
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}
