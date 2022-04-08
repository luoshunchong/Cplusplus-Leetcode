// @algorithm @lc id=100295 lang=cpp 
// @title shu-zhi-de-zheng-shu-ci-fang-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(2.00000,10)=1024.00000
// @test(2.10000,3)=9.26100
// @test(2.00000,-2)=0.25000
// @test(2.00000,-2147483648)=1.00000
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) return 1;
        if (x == 0) return 0;
        if (n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        double res = 1.0;
        while (n > 0) {
            if (n & 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
};