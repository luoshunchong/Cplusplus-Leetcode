// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem50.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        // //注意边界情况
        // //n=0,n<0,x=0,x=1
        // double res = 1;
        // if (x == 0 && n != 0) return 0;
        // if (n == 0 || x == 1) return 1;
        // if (n < 0) {
        //     n = abs(n);
        //     x = 1/x;
        // }
        // for (int i = 0; i < n; ++i) {
        //     res *= x;
        // }
        // return res;
        //以上方法超出实现限制，原因是循环的次数太大了

        /*
        利用位运算，循环2的次方次。细细理解这种解法。 
        */
        long long b = n;
        if (b < 0) b = -b;
        double res = 1;
        while (b) {
            if (b & 1) res *=x;
            x *= x;
            b >>= 1;
        }
        if (n < 0) res = 1 / res;
        return res;
    }
};
// @lc code=end

