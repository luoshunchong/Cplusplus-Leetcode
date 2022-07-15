// @algorithm @lc id=215 lang=cpp 
// @title kth-largest-element-in-an-array

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,2,1,5,6,4],2)=5
// @test([3,2,3,1,2,4,5,5,6],4)=4
// @test([1],1)=1
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        BuildMaxHeap(nums, nums.size());
        int temp = nums.size() - k;
        for (int i = nums.size() - 1; i >= temp; --i) {
            cout << 1 << endl;
            swap(nums[0], nums[i]);
            AdjustDown(nums, 0, i);
        }
        return nums[nums.size() - k];
    }
    void BuildMaxHeap(vector<int>& nums, int len) {
        for (int i = len / 2 - 1; i >= 0; --i) {
            AdjustDown(nums, i, len);
        }
    }
    void AdjustDown(vector<int>& nums, int k, int len) {
        for (int i = 2 * k + 1; i < len; i = i * 2 + 1) {
            if (i + 1 < len && nums[i] < nums[i + 1]) i++;
            if (nums[k] > nums[i]) break;
            else {
                swap(nums[k], nums[i]);
                k = i;
            }
        }
    }
};