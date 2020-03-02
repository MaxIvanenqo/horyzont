#include <stdio.h>

void merge(unsigned int a[], int low, int high) {
    if (high == low) return;
    if (high - low == 1) { 
        if (a[high] < a[low]){
            int tmp = a[high];
            a[high] = a[low];
            a[low] = tmp;
          }
        return;
    }
    int mid = (high + low) / 2;
    merge(a, low, mid);
    merge(a, mid + 1, high);

    unsigned int buffer[high];
    int xlow = low;
    int xhigh = mid + 1;
    int cur = 0;
    while (high - low + 1 != cur) {
        if (xlow > mid)
            buffer[cur++] = a[xhigh++];
        else if (xhigh > high)
            buffer[cur++] = a[xlow++];
        else if (a[xlow] > a[xhigh])
            buffer[cur++] = a[xhigh++];
        else buffer[cur++] = a[xlow++];
    }
    for (int i = 0; i < cur; i++)
        a[i + low] = buffer[i];
}

int main() {    

  int a, b, c, n, k;
  scanf("%d %d %d %d %d", &a, &b, &c, &n, &k);
  unsigned int x[n];
  for (int i = 0; i < n; ++i){
    x[i] = (a*i*i + b*i + c);
  }

  merge(x, 0, n-1);

  for (int i = 0; i < n; ++i){
    if (x[i] % k == 0) printf ("%u ", x[i]);
  }
  printf ("\n");
  return 0;
}