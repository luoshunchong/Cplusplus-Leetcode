/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left=0,right=nums.size()-1,mid,temp;
        bool flag=true;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                flag=false;
                break;
            } 
            else if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        while(flag==false){
            temp=mid;
            while(temp>0){
                --temp;
                if(nums[temp]<target){
                    res.push_back(++temp);
                    break;
                }
            }
            while(temp<nums.size()-1){
                ++temp;
                if(nums[temp]>target){
                    res.push_back(--temp);
                    break;
                }
            }
        }
        
        if(res.empty()){
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};
// @lc code=end

