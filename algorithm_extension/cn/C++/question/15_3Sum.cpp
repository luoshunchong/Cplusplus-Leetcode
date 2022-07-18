// @algorithm @lc id=15 lang=cpp 
// @title 3sum

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "algm/algm.h"
using namespace std;
// @test([-1,0,1,2,-1,-4])=[[-1,-1,2],[-1,0,1]]
// @test([0,1,1])=[]
// @test([0,0,0])=[[0,0,0]]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 4) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            vector<pair<int, int>> temp = twoSum(nums, i + 1, nums.size() - 1, -nums[i]);
            if (temp.size() != 0) {
                for (auto t : temp) {
                    res.push_back({nums[i], t.first, t.second});
                }
                cout << endl;
            }
        }
        return res;
    }
    vector<pair<int, int>> twoSum(vector<int>& nums, int left, int right, int target) {
        vector<pair<int, int>> res;
        while (left < right) {
            if (nums[left] + nums[right] > target) right--;
            else if (nums[left] + nums[right] < target) left++;
            else {
                res.push_back({left, right});
                //防止重复
                while (left + 1 < right && nums[left + 1] == nums[left]) left++;
                while (right - 1 > left && nums[right - 1] == nums[right]) right--;
            }
        }
        for (auto r : res) {
            cout << r.first << r.second << " ";
        }
        cout << endl;
        return res;
    }
};