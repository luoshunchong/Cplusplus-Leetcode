// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem96.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution
{
public:
/*
这道题的难点在于如何推理出动态规划的递推公式。
*/
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end
