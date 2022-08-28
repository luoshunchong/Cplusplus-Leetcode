#include <iostream>

using namespace std;

/*
求n的阶乘
*/
int check(int n) {
    if (n == 1) return 1;
    return check(n - 1) * n;
}

int main() {
    int n = 4;
    cout << check(n) << endl;
    return 0;
}