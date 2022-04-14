// @algorithm @lc id=100318 lang=cpp 
// @title shu-zu-zhong-de-ni-xu-dui-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([7,5,6,4])=5
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // //动态规划，会超时
        // if (nums.size() == 0) return 0;
        // vector<int> dp(nums.size(), 0);
        // for (int i = 1; i < nums.size(); ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         if (nums[j] > nums[i]) {
        //             dp[i] += 1;
        //         }
        //     }
        // }
        // int res = 0;
        // for (auto a : dp) {
        //     res += a;
        // }
        // return res;

        //归并排序
        
    }
};