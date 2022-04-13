// @algorithm @lc id=100332 lang=cpp 
// @title zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("abcabcbb")=3
// @test("bbbbb")=1
// @test("pwwkew")=3
// @test(" ")=1
// @test("au")=2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //动态规划
        // if (s.size() == 0) return 0;
        // vector<int> dp(s.size());
        // dp[0] = 1;
        // int res = dp[0];
        // for (int i = 1; i < s.size(); ++i) {
        //     int temp = -1;
        //     for (int j = 0; j < i; ++j) {
        //         if (s[j] == s[i]) temp = j;
        //     }
        //     if (dp[i - 1] >= (i - temp)) dp[i] = i - temp;
        //     else dp[i] = dp[i - 1] + 1;
        //     res = max(res, dp[i]);
        // }
        // return res;


    }
};