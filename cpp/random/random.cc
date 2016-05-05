#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

class Random
{
public:
  Random(): seed_(0)
  {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    seed_ = static_cast<unsigned int>(tv.tv_sec ^ tv.tv_usec);
  }
  Random(unsigned int seed):  seed_(seed)
  {
  }

  int Next()
  {
    return rand_r(&seed_);
  }

private:
  unsigned int seed_;
};

int main(int argc, char *argv[])
{
  Random myrand;
  for (int i = 0; i < 1000; ++i)
  {
    std::cout << myrand.Next() << std::endl;
  }
  return 0;
}

