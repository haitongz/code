#include <bitset>
#include <vector>
//#include "stdint.h"
#include <iostream>
#include <functional>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include <boost/dynamic_bitset.hpp>
using namespace boost;

struct timeval start, end;

void startTimer()
{
  gettimeofday(&start,NULL);
}
void stopTimer()
{
  gettimeofday(&end,NULL);
}
int getMs()
{
  return  (end.tv_sec - start.tv_sec)*1000 + (end.tv_usec-start.tv_usec)/1000;
}
int getUs()
{
  return  (end.tv_sec - start.tv_sec)*1000*1000 + (end.tv_usec-start.tv_usec);
}

int main()
{
  // empty constructor
  const int NUM = 10000000;
  std::vector<uint64_t>  bitwise_v;
  std::vector<std::bitset<64> >  bitset_v;
  std::vector<boost::dynamic_bitset<> > boost_bitset_v;

  for (int i = 0; i < NUM; ++i)
  {
    std::bitset<64> v(i);
    boost::dynamic_bitset<> dv(64, i);
    bitset_v.push_back(v);
    bitwise_v.push_back(v.to_ulong());
    boost_bitset_v.push_back(dv);
  }

  uint64_t biter = 100;
  std::bitset<64> bitseter(100);
  boost::dynamic_bitset<> boost_bitsetr(64, 100);
  int wise_count = 0;
  int bitset_count = 0;
  int boost_count = 0;
  startTimer();
  for (std::vector<uint64_t>::const_iterator wisei = bitwise_v.begin(); wisei != bitwise_v.end(); ++wisei) {
    if ((biter & *wisei ) == biter)
    {
      wise_count++;
    }
  }
  stopTimer();
  std::cout << "time cost Ms: " << getMs() << std::endl;
  std::cout << "time cost Us: " << getUs() << std::endl;
  std::cout << "wise_count: " << wise_count << std::endl;

  startTimer();
  for (std::vector<std::bitset<64> >::const_iterator seti = bitset_v.begin(); seti != bitset_v.end(); ++seti) {
    if ((bitseter & *seti) == bitseter)
    {
      bitset_count++;
    }
  }
  stopTimer();
  std::cout << "time cost Ms: " << getMs() << std::endl;
  std::cout << "time cost Us: " << getUs() << std::endl;
  std::cout << "biter_count: " << bitset_count << std::endl;

// boost dynamic bitset
  startTimer();
  for (std::vector<boost::dynamic_bitset<> >::const_iterator dbi = boost_bitset_v.begin(); dbi != boost_bitset_v.end(); ++dbi) {
    if ((boost_bitsetr & *dbi) == boost_bitsetr)
    {
      boost_count++;
    }
  }
  stopTimer();
  std::cout << "time cost Ms: " << getMs() << std::endl;
  std::cout << "time cost Us: " << getUs() << std::endl;
  std::cout << "boost_count: " << boost_count << std::endl;
  // unsigned long long constructor
  //std::bitset<8> b02(42);          // [0,0,1,0,1,0,1,0]
  //std::bitset<70> bl(ULLONG_MAX); // [0,0,0,0,0,0,1,1,1,...,1,1,1] in C++11
  //std::bitset<8> bs(0xfff0);      // [1,1,1,1,0,0,0,0]

  //// string constructor
  //std::string bit_string = "110010";
  //std::bitset<8> b3(bit_string); // [0,0,1,1,0,0,1,0]
  //std::bitset<8> b4(bit_string, 2); // [0,0,0,0,0,0,1,0]
  //std::bitset<8> b5(bit_string, 2, 3); // [0,0,0,0,0,0,0,1]

  //// string constructor using custom zero/one digits
  //std::string alpha_bit_string = "aBaaBBaB";
  //std::bitset<8> b6 (alpha_bit_string, 0, alpha_bit_string.size(), 'a', 'B'); // [0,1,0,0,1,1,0,1]

  //// char* constructor using custom digits
  //std::bitset<8> b7("XXXXYYYY", 8, 'X', 'Y');

  //std::cout << b01 << '\n' << b02 << '\n' << bl << '\n' << bs << '\n'
  //<< b3 << '\n' << b4 << '\n' << b5 << '\n' << b6 << '\n'
  //<< b7 << '\n';

  //// bitwise operation
  //std::bitset<4> b1("0110");
  //std::bitset<4> b2("0011");
  //std::cout << "b1 & b2: " << (b1 & b2) << '\n';
  //std::cout << "b1 | b2: " << (b1 | b2) << '\n';
  //std::cout << "b1 ^ b2: " << (b1 ^ b2) << '\n';

  //// operation all any none
  //std::bitset<4> bo1("0000");
  //std::bitset<4> bo2("0101");
  //std::bitset<4> bo3("1111");

  //std::cout << "bitset\t" << "all\t" << "any\t" << "none\n";
  //std::cout << bo1 << '\t' << bo1.all() << '\t' << bo1.any() << '\t' << bo1.none() << '\n';
  //std::cout << bo2 << '\t' << bo2.all() << '\t' << bo2.any() << '\t' << bo2.none() << '\n';
  //std::cout << bo3 << '\t' << bo3.all() << '\t' << bo3.any() << '\t' << bo3.none() << '\n';
}

