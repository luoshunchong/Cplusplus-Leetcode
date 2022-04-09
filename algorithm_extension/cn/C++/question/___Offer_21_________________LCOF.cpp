// @algorithm @lc id=100291 lang=cpp 
// @title diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3,4])=[1,3,2,4]
// @test([1,3,5])=[1,3,5]
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        //双指针
        if (nums.size() <= 1) return nums;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (((nums[left] & 1) == 0) && (nums[right] & 1)) {
                // swap(nums[left], nums[right]);
                // nums[left] = nums[left] + nums[right];
                // nums[right] = nums[left] - nums[right];
                // nums[left] = nums[left] - nums[right];

                nums[left] = nums[left] ^ nums[right];
                nums[right] = nums[left] ^ nums[right];
                nums[left] = nums[left] ^ nums[right];

            }
            while (left < nums.size() && nums[left] & 1) left++;
            while (right > 0 && (nums[right] & 1) == 0) right--;
        }
        return nums;
    }
};