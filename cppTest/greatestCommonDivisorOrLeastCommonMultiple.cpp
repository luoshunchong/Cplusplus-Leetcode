#include <iostream>

using namespace std;

/*
最大公因数
*/
void gcd(int a, int b) {
    while (a % b) {
        int r = a % b;
        a = b;
        b = r;
    }
    cout << "最大公因数" << b << endl;
    cout << "最小公倍数" << (a * b) / b  << endl;
}
/*
最小公倍数
*/
void lcm(int a, int b) {
    while (a % b) {
        int r = a % b;
        a = b;
        b = r;
    }
    cout << "最小公倍数" << a << endl;
}

int main() {
    int a = 35, b = 28;
    gcd(a, b);
    lcm(a, b);
    return 0;
}