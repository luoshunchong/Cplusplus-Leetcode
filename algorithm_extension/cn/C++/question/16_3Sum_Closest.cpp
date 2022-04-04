// @algorithm @lc id=16 lang=cpp 
// @title 3sum-closest


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "algm/algm.h"
using namespace std;
// @test([-1,2,1,-4],1)=2
// @test([0,0,0],1)=0
// @test([0,0,1],1)=1
// @test([0,2,1,-3], 1)=0
// @test([1,1,1,1], -100)=3
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0x3f3f3f3f; // 定义最大值
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return sum;
                if (abs(sum - target) < abs(res - target)) res = sum;
                if (sum > target) right--;
                else left++;
            }
        }
        return res;
    }
};