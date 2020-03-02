/*#include <iostream>
int q_pows(int a, int b, int m);
void q_pows_init(int *p, int &i);

int main(){
  int n, i = 0;
  std::cin >> n;
  int *p = new int[n];
  while (i < n) q_pows_init(p, i);
  i = 0;
  while (i < n){
    std::cout << p[i] << std::endl;
    i++;
  }
  return 0;
}

void q_pows_init(int *p, int &i){
  int a, b, m;
  std::cin >> a >> b >> m;
  p[i] = q_pows(a % m, b, m);
  i++;
}

//Loop
int q_pows(int a, int b, int m){ 
  int c = 1;
  a %= m;
  while (b > 0){
    if (b % 2 != 0) c = (c * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return c;
}*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int modulo(int a,int b,int n){
long long x=1,y=a;
  while(b > 0){
    if(b%2 == 1){
      x=(x*y)%n;
    }
  y = (y*y)%n;
  b /= 2;
  }
  return x%n;
}
int main(){
  int t;
  cin >> t;
  for(int i=0;i<t;i++){
    int a,b,m;
    scanf("%d %d %d", &a, &b, &m);
    printf("%d\n",(int)modulo(a,b,m));
}
return 0;
}

//Recursion
/*int q_pows(int a, int b, int m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  int c = q_pows(a, b / 2, m);
  if (b % 2 == 0) return ((c % m) * c);
  else return ((a * c) % m * c) % m;
}*/