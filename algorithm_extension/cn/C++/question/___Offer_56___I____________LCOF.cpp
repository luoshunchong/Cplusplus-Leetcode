// @algorithm @lc id=100320 lang=cpp 
// @title shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        //依次异或数组中的所有数字
        int temp = 0;
        for (auto a : nums) {
            temp ^= a;
        }
        //找到任意一个位为1的位置
        int ret = 1;
        while ((temp & ret) == 0) ret <<= 1;
        //在两个数组中分别异或找到两个数
        int a = 0, b = 0;
        for (auto t : nums) {
            if (ret & t) {
                a ^= t;
            }
            else {
                b ^= t;
            }
        }
        return vector<int> {a, b};
    }
};