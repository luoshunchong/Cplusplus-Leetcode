// #include <iostream>

// using namespace std;

// int get_num(int n) {
//     int tot = 1;
//     for (int i = 2; i * i <= n; ++i) {
//         if (n % i== 0) {
//             int x = 0;
//             while (n % i == 0) {
//                 n /= i;
//                 x++;
//             }
//             tot *= (x + 1);
//         }
//     }
//     if (n > 1) tot *= 2;
//     return tot;
// }

// int main() {
//     int n;
//     while (cin >> n) {
//         cout << get_num(n) << endl; //求n的因子个数
//     }
//     return 0;
// }

#include <iostream>

using namespace std;

int get_sum(int n) {
    int tot = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int mul = 1;
            while (n % i == 0) {
                n /= i;
                mul *= i;
            }
            tot *= (mul * i - 1) / (i - 1);
        }
    }
    if (n > 1) tot *= (n + 1);
    return tot;
}

int main() {
    int n;
    while (cin >> n) {
        cout << get_sum(n) << endl; //求n的因子数之和
    }
    return 0;
}