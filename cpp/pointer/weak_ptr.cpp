#compile fail because g++ version
#include <iostream>
#include <memory>

std::weak_tpr<int> gw;

void f()
{
  if (auto spt = gw.lock())
  {
    std::cout << *spt << std::endl;
  }
  else
  {
    std::cout << "gw is expired" << std::endl;
  }
}

int main(int argc, char *argv[])
{
  {
    auto sp = std::make_shared<int>(42);
    gw = sp;

    f();
  }
  f();
  return 0;
}
