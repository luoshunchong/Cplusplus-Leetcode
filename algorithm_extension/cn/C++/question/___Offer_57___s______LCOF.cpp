// @algorithm @lc id=100322 lang=cpp 
// @title he-wei-sde-liang-ge-shu-zi-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([2,7,11,15],9)=[2,7]
// @test([10,26,30,31,47,60],40)=[10,30]
// @test([2,7,11,15],14)=[]
// @test([2,7,11,15],18)=[7,11]
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //固定一个位置，下一个位置使用二分法
        if (nums.size() == 0) return {};
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                if ((nums[i] + nums[mid]) == target) return vector<int>{nums[i], nums[mid]};
                else if ((nums[i] + nums[mid]) > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return {};
    }
};