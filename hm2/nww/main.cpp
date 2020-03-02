#include <iostream>
long long nwd(long long a, long long b) {
    if(a == 0) return b;
    return nwd(b % a, a);
}
long long nww(long long a, long long b){
    if(a == 0) return b;
    return (a / nwd(a, b)) * b;
}
int main() {
    long long n, m = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        m = nww(m, a);
    }
    std::cout << m << std::endl;
    return 0;
}