// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem81.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int temp=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]<nums[i-1]){
                temp=i;
                break;
            }
        }
        bool l=find(nums,target,0,temp-1);
        bool r=find(nums,target,temp,nums.size()-1);
        return l||r;
    }

    bool find(vector<int>& nums,int target,int left,int right){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};
// @lc code=end

