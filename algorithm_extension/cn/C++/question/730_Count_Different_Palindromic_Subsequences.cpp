// @algorithm @lc id=730 lang=cpp 
// @title count-different-palindromic-subsequences

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "algm/algm.h"
using namespace std;
// @test("bccb")=6
// @test("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba")=104860361
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int dp[4][1001][1001];
        memset(&dp, 0, sizeof(dp));
        int mod = 1e9+7, n = s.size(), ans = 0;

        for(int i = 0; i < n; ++i)
            dp[s[i]-'a'][i][i] = 1;

        for(int l = n-2; l >= 0; --l) {
            for(int r = l+1; r < n; ++r) {
                for(int i = 0; i < 4; ++i) {
                    if(s[l] == s[r] && s[l] == (i+'a')) {
                        dp[i][l][r] = 2;
                        for(int k = 0; k < 4; ++k)
                            dp[i][l][r] = (dp[i][l][r] + dp[k][l+1][r-1])%mod;
                    } else if (s[l] == (i+'a')) {
                        dp[i][l][r] = dp[i][l][r-1];
                    } else if (s[r] == i+'a') {
                        dp[i][l][r] = dp[i][l+1][r];
                    } else {
                        dp[i][l][r] = dp[i][l+1][r-1];
                    }
                }
            }
        }
        for(int i = 0; i < 4; ++i)
            ans = (ans + dp[i][0][n-1])%mod;
        return ans;
    }
};