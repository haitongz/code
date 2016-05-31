#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <sys/time.h>

const int LOOP_COUNT = 10000000;
std::string IntToString(int value)
{
  char temp[255] =
  { 0 };

  sprintf(temp, "%d", value);

  return std::string(temp);
}

int main(int argc, char *argv[])
{
  int32_t x = 123421421;
  struct timeval start, end;
  std::string result;
  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    result = IntToString(x);
  }
  gettimeofday(&end, NULL);
  std::cout << "IntToString timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  gettimeofday(&start, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i)
  {
    result = std::to_string(x);
  }
  gettimeofday(&end, NULL);
  std::cout << " timeuse: " << 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << std::endl;

  return 0;
}
