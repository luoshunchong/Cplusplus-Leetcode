#include <iostream>

using namespace std;

/*
最大公因数
*/
void gcd(int a, int b) {
    int num1 = a, num2 = b;
    while (a % b) {
        int r = a % b;
        a = b;
        b = r;
    }
    cout << "最大公因数" << b << endl;
    cout << "最小公倍数" << (num1 * num2) / b  << endl;
}
int gcd1(int x, int y) {
    return y ? gcd1(y, x % y) : x;
}
/*
最小公倍数
*/
void lcm(int a, int b) {
    int num1 = a, num2 = b;
    while (a % b) {
        int r = a % b;
        a = b;
        b = r;
    }
    cout << "最小公倍数" << (num1 * num2) / b  << endl;
}

int main() {
    int a = 4, b = 15;
    gcd(a, b);
    lcm(a, b);
    cout << gcd1(a, b) << endl;
    return 0;
}