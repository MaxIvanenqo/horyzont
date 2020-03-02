/*Napisz program, który czyta dwa ciągi uporządkowane niemalejąco i scala je w jeden ciąg uporządkowany niemalejąco.
Wejście

W pierwszym wierszu znajduje się liczba naturalna n <= 100000. Każdy z dwóch następnych wierszy zawiera niemalejący ciąg n liczb całkowitych.
Wyjście

Wynikowy ciąg złożony z 2n liczb.*/
#include <stdio.h>

void merge(int a[], int low, int high) {
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

    int buffer[high];
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


int main()
{
	int n;
  scanf("%d", &n);
  int z[n];
  for (int i = 0; i < n; ++i){
  	scanf("%d", &z[i]);
  }
  merge(z, 0, n - 1);
  for (int i = 0; i < n; ++i){
    printf ("%d ", z[i]);
  }
  printf ("\n");
  return 0;
}