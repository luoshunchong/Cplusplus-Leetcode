// @algorithm @lc id=100292 lang=cpp 
// @title er-jin-zhi-zhong-1de-ge-shu-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(13)=3
// @test(128)=1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};