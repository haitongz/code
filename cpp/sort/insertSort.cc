#include <iostream>

void swap(int a[], int index1, int index2)
{
  int tmp = a[index1];
  a[index1] = a[index2];
  a[index2] = tmp;
}

void PrintArray(int a[], int length)
{
  for (int i = 0; i < length; ++i)
  {
    std::cout << a[i] << " " << std::endl;
  }
}

void InsertSort(int a[], int n)
{
  int index = 0;
  for (int i = 1; i < n; ++i)
  {
    index = i;
    while (index > 0)
    {
      if (a[index-1] > a[index])
      {
        swap(a, index-1, index);
        index--;
      }
      else
      {
        break;
      }
    }
  }
}


int main(int argc, char *argv[])
{
  int a[8] = {3,1,5,7,2,4,9,6};
  InsertSort(a, 8);
  PrintArray(a, 8);
  return 0;
}
