// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem34.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     vector<int> res;
    //     int left=0,right=nums.size()-1,mid,temp;
    //     bool flag=true;
    //     while(left<=right){
    //         mid=left+(right-left)/2;
    //         if(nums[mid]==target){
    //             flag=false;
    //             break;
    //         }
    //         else if(nums[mid]<target) left=mid+1;
    //         else right=mid-1;
    //     }
    //     while(flag==false){
    //         temp=mid;
    //         while(temp>0){
    //             --temp;
    //             if(nums[temp]<target){
    //                 res.push_back(++temp);
    //                 break;
    //             }
    //         }
    //         while(temp<nums.size()-1){
    //             ++temp;
    //             if(nums[temp]>target){
    //                 res.push_back(--temp);
    //                 break;
    //             }
    //         }
    //     }

    //     if(res.empty()){
    //         res.push_back(-1);
    //         res.push_back(-1);
    //     }
    //     return res;
    // }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        vector<int> res;
        int left = 0;
        int right = nums.size() - 1;
        int temp = -1;
        bool b = false; //定义是否找到标志
        //二分查找找到target的大致位置
        while (left <= right)
        {
            temp = left + (right - left) / 2;
            if (nums[temp] == target)
            {
                b = true;
                break;
            }
            else if (nums[temp] > target)
                right = temp - 1;
            else
                left = temp + 1;
        }
        if (b)
        {
            int t = temp;
            //向左搜索
            while (temp >= 0)
            {
                if (nums[temp] == target)
                    --temp;
                else
                {
                    res.push_back(temp + 1);
                    break;
                }
            }
            //防止temp小于数组边界，未执行push_back
            if (temp < 0)
                res.push_back(temp + 1);
            //向右搜索
            while (t <= nums.size() - 1)
            {
                if (nums[t] == target)
                    ++t;
                else
                {
                    res.push_back(t - 1);
                    break;
                }
            }
            //防止t大于数组边界，未执行push_back
            if (t > nums.size() - 1)
                res.push_back(t - 1);
        }
        else
        {
            return {-1, -1};
        }
        return res;
    }
};
// @lc code=end
