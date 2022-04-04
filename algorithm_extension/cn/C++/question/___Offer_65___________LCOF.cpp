// @algorithm @lc id=100335 lang=cpp 
// @title bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(1, 1)=2
// @test(-1, 2)=1
// @test(5, 17)=22
class Solution {
public:
    int add(int a, int b) {
        while (b) {
            int carry = a & b; // 计算 进位
            a = a ^ b; // 计算 本位
            b = (unsigned)carry << 1;
        }
        return a;
    }
};