// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem35.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
public:
    // int searchInsert(vector<int> &nums, int target)
    // { //左闭右闭
    //     if (nums.size() == 0)
    //         return 0;
    //     int left = 0;
    //     int right = nums.size() - 1;
    //     int temp = -1;
    //     while (left <= right)
    //     {
    //         temp = left + (right - left) / 2; //防止溢出
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
    //     return nums[temp] > target ? temp : temp + 1;
    // }

    int searchInsert(vector<int> &nums, int target)
    { //左闭右开
        if (nums.size() == 0)
            return 0;
        int left = 0;
        int right = nums.size();
        int temp = -1;
        while (left < right)
        {
            temp = left + (right - left) / 2; //防止溢出
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
        return nums[temp] > target ? temp : temp + 1;//巧妙运用比大小确定数字放到位置
    }
};
// @lc code=end
