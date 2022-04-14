// @algorithm @lc id=100321 lang=cpp 
// @title shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,4,3,3])=4
// @test([9,1,7,9,7,9,7])=1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32, 0); //int型占4个字节，一个字节8位，共32位，除去符号位31位。
        for (auto a : nums) {
            int i = 0;
            while (a) {
                bit[i] += (a & 1);
                a >>= 1;
                i++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            //利用%3 来求得对应位置上有没有1 有的话乘对应的 2 的i次方
            res += (1 << i) *(bit[i] % 3);
        }
        return res;
    }
};