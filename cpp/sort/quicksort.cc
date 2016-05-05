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
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

//快速排序版本1
//挖坑填数法
void QuickSort1(int s[], int l, int r)
  if (l < r)
  {
    //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1 有时会取中间的数作为基准数
    int i = l, j = r, x = s[l];
    while (i < j)
    {
      while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
        j--;
      if(i < j)
        s[i++] = s[j];

      while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
        i++;
      if(i < j)
        s[j--] = s[i];
    }
    s[i] = x;
    QuickSort(s, l, i - 1); // 递归调用
    QuickSort(s, i + 1, r);
  }
}

// 小于池子填数法
//
void partition(int s[], int l, int r)
{
  int pivot = l-1;
  int index = l;
  while (index <= right)
  {
    if (s[index] <= s[right])
    {
      swap(s, ++pivot, index);
    }
    index++;
  }
  return pivot;
}

void QuickSort2(int s[], int l, int r)
{
  if (l < r)
  {
    int random = left +
  }

}



int main(int argc, char *argv[])
{
  int a[8] = {3,1,5,7,2,4,9,6};
  PrintArray(a, 8);
  QuickSort(a, 0, 7);
  PrintArray(a, 8);
  return 0;
}
