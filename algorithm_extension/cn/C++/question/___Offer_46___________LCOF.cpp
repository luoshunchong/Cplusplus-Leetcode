// @algorithm @lc id=100325 lang=cpp 
// @title ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(12258)=5
// @test(0)=1
class Solution {
public:
    int translateNum(int num) {
        //动态规划
        //把数字转换成字符串
        string s = to_string(num);
        int len = s.size();
        vector<int> dp(len + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= len; ++i) {
            dp[i] = dp[i - 1] + check(s[i - 2], s[i - 1]) * dp[i - 2];
        }
        return dp[len];
    }
    int check(char a, char b) {
        string temp = {a, b};
        int num = stoi(temp);
        if (num >= 10 && num <= 25) {
            return 1;
        }
        else {
            return 0;
        }
    }
};