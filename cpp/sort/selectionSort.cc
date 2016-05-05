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

int GetMinIndex(int a[], int begin_index, int end_index)
{
  int min_index = begin_index;
  for (int i = begin_index; i < end_index; ++i)
  {
    if (a[min_index] > a[i+1])
    {
      min_index = i+1;
    }
  }
  return min_index;
}

void SelectionSort(int a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    int min_index = GetMinIndex(a, i, n-1);
    swap(a, i, min_index);
  }
}


int main(int argc, char *argv[])
{
  int a[8] = {3,1,5,7,2,4,9,6};
  SelectionSort(a, 8);
  PrintArray(a, 8);
  return 0;
}
