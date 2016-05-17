#include <iostream>
#include <string>

int main()
{
    std::string s("123456789afdsafdajsfksajfdsakfdjaslfkjaslfkja");
    std::cout << "Default-constructed capacity is " << s.capacity() << '\n';
    s.resize(100);
    std::cout << "Capacity of a 100-element string is " << s.capacity() << '\n';
    s.clear();
    std::cout << "Capacity after clear() is " << s.capacity() << '\n';
    s.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << s.capacity() << '\n';
    std::cout << s << std::endl;
}
