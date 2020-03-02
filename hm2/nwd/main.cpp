#include <iostream>
int nwd(int m, int n) {
    if(m == 0) return n;
    else return nwd(n % m, m);
}
 
int main() {
    int n, m = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        m = nwd(m, a);
    }
    std::cout << m << std::endl;
    return 0;
}