#include <cassert>
#include <string>

void f(std::string & s)
{
  std::string::size_type new_capacity{ 100u };
  s.reserve(new_capacity);
  assert(new_capacity <= s.capacity());
}
int main()
{
    std::string s;
    std::string::size_type new_capacity{ 100u };
    assert(new_capacity > s.capacity());
    f(s);

}
