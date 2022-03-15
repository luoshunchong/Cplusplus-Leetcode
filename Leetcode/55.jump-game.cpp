// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem55.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // vector<int> index;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     index.push_back((nums[i] + i));
        // }
        // int jump = 0;
        // int max_index = index[0];
        // while (jump < index.size() && jump <= max_index)
        // {
        //     if (max_index <= index[jump])
        //     {
        //         max_index = index[jump];
        //     }
        //     jump++;
        //     if (jump == index.size())
        //     {
        //         return true;
        //     }
        // }
        // return false;

        int jump = 0;
        int max_index = nums[0];
        while (jump < nums.size() && jump <= max_index)
        {
            if (max_index <= (jump + nums[jump]))
            {
                max_index = (jump + nums[jump]);
            }
            jump++;
            if (jump == nums.size())
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
