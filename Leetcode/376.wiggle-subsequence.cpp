// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem376.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution
{
public:
    // int wiggleMaxLength(vector<int> &nums) //贪心、有限状态机
    // {
    //     if (nums.size() < 2)
    //         return nums.size();
    //     static const int begin = 0;
    //     static const int up = 1;
    //     static const int down = 2;
    //     int start = begin;
    //     int max_len = 1;
    //     for (int i = 1; i < nums.size(); ++i)
    //     {
    //         switch (start)
    //         {
    //         case begin:
    //             if (nums[i - 1] < nums[i])
    //             {
    //                 start = up;
    //                 max_len++;
    //             }
    //             else if (nums[i - 1] > nums[i])
    //             {
    //                 start = down;
    //                 max_len++;
    //             }
    //             break;
    //         case up:
    //             if (nums[i - 1] > nums[i])
    //             {
    //                 start = down;
    //                 max_len++;
    //             }
    //             break;
    //         case down:
    //             if (nums[i - 1] < nums[i])
    //             {
    //                 start = up;
    //                 max_len++;
    //             }
    //             break;
    //         }
    //     }
    //     return max_len;
    // }
};
// @lc code=end
