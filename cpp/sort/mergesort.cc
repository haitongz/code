#include <iostream>
using namespace std;
const int MAXN = 10900;
int a[MAXN], tmp[MAXN], n;
void Merge (int l, int m, int r) {
  int i = l;
  int j = m + 1;
  int k = l;
  while (i <= m && j <= r) {
    if (a[i] < a[j]) {
      tmp[k++] = a[i++];
    } else {
      tmp[k++] = a[j++];
    }
  }
  while (i <= m) {
    tmp[k++] = a[i++];
  }
  while (j <= r) {
    tmp[k++] = a[j++];
  }
  for (int i = l; i <= r; ++i)
    a[i] = tmp[i];
}
void Merge_sort (int l, int r) {
  if (l < r) {
    int m = (l + r) >> 1;
    Merge_sort (l, m);
    Merge_sort (m + 1, r);
    Merge (l, m, r);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int i, j, t, k, u, c, v, p, numCase = 0;
  while (cin >> n) {
    for (i = 0; i < n; ++i) {
      cin >> a[i];
    }
    Merge_sort(0, n - 1);
    for (i = 0; i < n; ++i) {
      cout << a[i] << endl;
    }
  }
  return 0;
}
