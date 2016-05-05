#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
      std::srand(std::time(0)); //use current time as seed for random generator
      int random_variable = std::rand();
      std::cout << "Random value on [0 " << RAND_MAX << "]: "
        << (int)((double)random_variable/RAND_MAX*10) << '\n' << random_variable << '\n';

      std::cout <<  (std::rand() % (10-0+1))+ 0<< std::endl;

}
