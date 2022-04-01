// @algorithm @lc id=718 lang=cpp 
// @title maximum-length-of-repeated-subarray


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3,2,1],[3,2,1,4,7])=3
// @test([0,0,0,0,0],[0,0,0,0,0])=5
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // //如果子数组不连续的话就需要加这一句
                // else {
                //     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                // }
                if (res < dp[i][j]) res = dp[i][j];
            }
        }
        return res;
    }
};