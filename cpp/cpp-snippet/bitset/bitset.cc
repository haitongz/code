#include <bitset>
#include <iostream>

int main()
{
  // empty constructor
  std::bitset<8> b01; // [0,0,0,0,0,0,0,0]

  // unsigned long long constructor
  std::bitset<8> b02(42);          // [0,0,1,0,1,0,1,0]
  std::bitset<70> bl(ULLONG_MAX); // [0,0,0,0,0,0,1,1,1,...,1,1,1] in C++11
  std::bitset<8> bs(0xfff0);      // [1,1,1,1,0,0,0,0]

  // string constructor
  std::string bit_string = "110010";
  std::bitset<8> b3(bit_string); // [0,0,1,1,0,0,1,0]
  std::bitset<8> b4(bit_string, 2); // [0,0,0,0,0,0,1,0]
  std::bitset<8> b5(bit_string, 2, 3); // [0,0,0,0,0,0,0,1]

  // string constructor using custom zero/one digits
  std::string alpha_bit_string = "aBaaBBaB";
  std::bitset<8> b6 (alpha_bit_string, 0, alpha_bit_string.size(), 'a', 'B'); // [0,1,0,0,1,1,0,1]

  // char* constructor using custom digits
  std::bitset<8> b7("XXXXYYYY", 8, 'X', 'Y');

  std::cout << b01 << '\n' << b02 << '\n' << bl << '\n' << bs << '\n'
    << b3 << '\n' << b4 << '\n' << b5 << '\n' << b6 << '\n'
    << b7 << '\n';

  // bitwise operation
  std::bitset<4> b1("0110");
  std::bitset<4> b2("0011");
  std::cout << "b1 & b2: " << (b1 & b2) << '\n';
  std::cout << "b1 | b2: " << (b1 | b2) << '\n';
  std::cout << "b1 ^ b2: " << (b1 ^ b2) << '\n';

  // operation all any none
    std::bitset<4> bo1("0000");
    std::bitset<4> bo2("0101");
    std::bitset<4> bo3("1111");

    std::cout << "bitset\t" << "all\t" << "any\t" << "none\n";
    std::cout << bo1 << '\t' << bo1.all() << '\t' << bo1.any() << '\t' << bo1.none() << '\n';
    std::cout << bo2 << '\t' << bo2.all() << '\t' << bo2.any() << '\t' << bo2.none() << '\n';
    std::cout << bo3 << '\t' << bo3.all() << '\t' << bo3.any() << '\t' << bo3.none() << '\n';
}

