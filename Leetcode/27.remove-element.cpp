// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem27.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution
{
public:
    // int removeElement(vector<int> &nums, int val)
    // { //双指针
    //     int i = 0;
    //     int j = 0;
    //     while (i < nums.size())
    //     {
    //         if (nums[i] != val)
    //         {
    //             nums[j] = nums[i];
    //             ++i;
    //             ++j;
    //         }
    //         else
    //         {
    //             ++i;
    //         }
    //     }
    //     return j;
    // }

    int removeElement(vector<int> &nums, int val)
    { //双指针，简洁版
        int j = 0;
        for(int i =0;i<nums.size();++i){
            if(val!=nums[i]) nums[j++] = nums[i];
        }
        return j;
    }
};
// @lc code=end
