#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class S;
int main()
{
    char* p;
    p = (char *)malloc(2048);
    int* p2 = static_cast<std::nullptr_t>(NULL);
    void(*f)(int) = NULL;
    int S::*mp = NULL;
    void(S::*mfp)(int) = NULL;
    p[0] = 0;
    if (p == NULL)
    {
      std::cout << "null..." << std::endl;
    }
}
