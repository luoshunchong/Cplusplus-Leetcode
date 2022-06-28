// @algorithm @lc id=324 lang=cpp 
// @title wiggle-sort-ii

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "algm/algm.h"
using namespace std;
// @test([1,5,1,1,6,4])=[1,6,1,5,1,4]
// @test([1,3,2,2,3,1])=[2,3,1,3,1,2]
// @test([2,1,1,3,2,2])=[2,3,1,2,1,2]
class Solution
{
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 1) return;
        sort(nums.begin(), nums.end());
        int mid = (nums.size() + 1) / 2;
        reverse(nums, 0, mid - 1);
        reverse(nums, mid, nums.size() - 1);
        //穿插构建
        vector<int> arr1(nums.begin(), nums.begin() + mid);
        vector<int> arr2(nums.begin() + mid, nums.end());
        for (int i = 0, j = 0; i < nums.size(); i += 2, j++) {
            nums[i] = arr1[j];
            if (j < arr2.size()) nums[i + 1] = arr2[j];
        }
    }
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};