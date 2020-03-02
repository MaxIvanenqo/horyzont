#include <stdio.h>
int getPeriod(int m) { 
  int a = 0, b = 1, c = a + b; 
  for (int i = 0; i < m * m; i++) { 
    c = (a + b) % m; 
    a = b;
    b = c;
    if (a == 0 && b == 1) return i + 1;
  } 
} 
 
int fib(int n, int m) { 
  n++;
  int tmp = n % getPeriod(m); 
  int p[2] = {0, 1};
  int ans = tmp; 
 
  for (int i = 1; i < tmp; i++) { 
    ans = (p[0] + p[1]) % m; 
    p[0] = p[1]; 
    p[1] = ans;
  } 
 return ans % m; 
} 
 
int main() 
{ 
  int a, m = 10000;
  scanf("%d",&a); 
  printf("%d\n",(int)fib(a, m)); 
  return 0; 
}