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
        int res = INT_MAX;
        vector<long long> presum(nums.size() + 1, 0);
        deque<int> deq;
        for (int i = 1; i <= nums.size(); ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < presum.size(); ++i) {
            while (!deq.empty() && presum[i] - presum[deq.front()] >= k) {
                res = min(res, i - deq.front());
                deq.pop_front();
            }
            while (!deq.empty() && presum[deq.back()] >= presum[i]) deq.pop_back();
            deq.push_back(i);
        }
        return res == INT_MAX ? -1 : res; 
    }
};