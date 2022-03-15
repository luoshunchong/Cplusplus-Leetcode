// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1049.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    { //动态规划，抽象成0-1背包问题
        /*
        本题其实就是尽量让石头分成重量相同的两堆，相撞之后剩下的石头最小。
        本题物品的重量为store[i]，物品的价值也为store[i]。
        */
        int sum = 0;
        for (int i = 0; i < stones.size(); ++i)
            sum += stones[i];
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = target; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};
// @lc code=end
