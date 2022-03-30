// @algorithm @lc id=643 lang=cpp 
// @title maximum-average-subarray-i


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,12,-5,-6,50,3],4)=12.75000
// @test([5],1)=5.00000
// @test([1,12,-5,-6],3)=2.66667
// @test([1,-2,-1],2)=-0.50000
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //双指针
        int left = 0, right = 1, maxNum = nums[0], res = INT_MIN, a = k - 1;
        while (right < nums.size()) {
            maxNum += nums[right];
            if (a) {
                a--;
                right++;
            }
            else {
                maxNum -= nums[left];
                right++;
                left++;
            }
            if (!a && res < maxNum) res = maxNum;
        }
        if (res < maxNum) res = maxNum;
        return (double)res / k;
    }
};