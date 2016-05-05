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

void BubbleSort(int a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    for(int j = 0; j < n-1-i; ++j)
    {
      if (a[j] > a[j+1])
      {
        swap(a, j, j+1);
      }
    }
  }
}


int main(int argc, char *argv[])
{
  int a[8] = {3,1,5,7,2,4,9,6};
  BubbleSort(a, 8);
  PrintArray(a, 8);
  return 0;
}
