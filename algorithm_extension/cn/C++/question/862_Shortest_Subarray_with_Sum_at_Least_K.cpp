// @algorithm @lc id=892 lang=cpp 
// @title shortest-subarray-with-sum-at-least-k


#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "algm/algm.h"
using namespace std;
// @test([1],1)=1
// @test([1,2],4)=-1
// @test([2,-1,2],3)=3
// @test([48,99,37,4,-31], 140)=2
// @test([17,85,93,-45,-21], 150)=2
// @test([84,-37,32,40,95], 167)=3
// @test([-28,81,-20,28,-29], 89)=3
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX, left = 0,sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum <= 0) {
                sum -= nums[left];
                left++;
            }
            while (sum >= k) {
                res = min(res, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? -1 : res; 
    }
};