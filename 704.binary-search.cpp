// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem704.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution
{
public:
    // int search(vector<int> &nums, int target)
    // { //方法一：<=，左闭右闭
    //     if (nums.size() == 0)
    //         return -1;
    //     int left = 0;
    //     int right = nums.size() - 1;
    //     while (left <= right)
    //     {
    //         int temp = left + (right - left) / 2;
    //         if (nums[temp] == target)
    //         {
    //             return temp;
    //         }
    //         else if (nums[temp] > target)
    //         {
    //             right = temp - 1;
    //         }
    //         else
    //         {
    //             left = temp + 1;
    //         }
    //     }
    //     return -1;
    // }

    int search(vector<int> &nums, int target)
    { //方法二：<，左闭右开区间
        if (nums.size() == 0)
            return -1;
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int temp = left + (right - left) / 2;
            if (nums[temp] == target)
            {
                return temp;
            }
            else if (nums[temp] > target)
            {
                right = temp;
            }
            else
            {
                left = temp + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
