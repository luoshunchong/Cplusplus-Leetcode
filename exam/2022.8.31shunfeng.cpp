/*
第一题：幸运数的定义，一个数在十进制下数字5至少出现了不少于5次称之为幸运数。给你一个数N，求大于N的最小幸运数。
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;

int ischeck(string s) {
    int index = 0;
    for (auto c : s) {
        if (c == '5') index++;
    }
    return index;
}

void check(long long N) {
    int pre5 = ischeck(to_string(N));
    for (long long i = N + 1; i < LONG_MAX; ++i) {
        int n = ischeck(to_string(i));
        if (n >= 5) {
            cout << i << endl;
            break;
        }
    }
}


int main() {
    long long N;
    cin >> N;
    check(N);
    return 0;
}

/*
第二题：有一个1到n的整数数组排列，让你猜每一个数字，小明会告诉你猜测的数字大小，大了，小了，正确，求最坏的情况下需要猜测几次？
*/

#include <iostream>
#include <cmath>

using namespace std;

void check(int n) {
    int x = int(log2(n));
    long long s = 0;
    for (int i = 0; i < x; ++i) {
        s += i * (long long)pow(2, i);
    }
    s += x * (n - (long long)pow(2, x) + 1) + n;
    cout << s << endl;
}

int main() {
    int N;
    cin >> N;
    check(N);
    return 0;
}