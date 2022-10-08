#include <iostream>
#include <climits>
#include <random>
#include <sys/time.h>

using namespace std;

class Solution {
public:
	//相加
    int add(int a, int b) {
        return b == 0 ? a : add(a ^ b, (a & b) << 1);
    }
	//相减
    int sub(int a, int b) {
        return add(a, negative(b));
    }

    int get_sign(int n) {
        if(n >> 31)
            return 1;
        else
            return 0;
    }
    int negative(int n) {
        return add(~n, 1);
    }

    int positive(int n) {
        if(n >> 31)
            return negative(n);
        else
            return n;
    }
	//相乘
    int multi(int a, int b) {
        bool be_negative = false;
        if(get_sign(a) ^ get_sign(b))
            be_negative = true;

        unsigned int x = positive(a);
        unsigned int y = positive(b);
        int n = 0;
        while(y | 0) {
            if(y & 1)
                n = add(n, x);
            x = x << 1;
            y = y >> 1;
        }
        return be_negative ? negative(n) : n;
    }
	//相除
    int div(int a, int b) {
        bool be_negative = false;
        if(get_sign(a) ^ get_sign(b))
            be_negative = true;
        unsigned int x = positive(a);
        unsigned int y = positive(b);

        int res = 0;
        int i = 31;
        while(i >= 0) {
            if((x >> i) >= y) {
                res = add(res, 1 << i);
                x = sub(x, y << i);
            }
            i = sub(i, 1);
        }
        //if(res < 0 && !be_negative)
        //    return INT_MAX;
        return be_negative ? negative(res) : res;
    }
};


int main() {
    Solution s;
    srand(unsigned(time(NULL)));
    int maxIteration = 10000;
    while(maxIteration--) {
       int a = rand() - INT_MAX / 2;
       int b = rand() - INT_MAX / 2;
       if(s.add(a, b) != a + b)
           cout << "error : " << a << " + " << b << endl;
       if(s.sub(a, b) != a - b)
           cout << "error : " << a << " - " << b << endl;
       if(s.multi(a, b) != a * b)
           cout << "error : " << a << " * " << b << " " << s.multi(a, b) << " " << a * b << endl;
       if(b != 0 && s.div(a, b) != a / b)
           cout << "error : " << a << " / " << b << endl;
    }

    return 0;
}