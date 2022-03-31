// @algorithm @lc id=100336 lang=cpp 
// @title hua-dong-chuang-kou-de-zui-da-zhi-lcof


#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "algm/algm.h"
using namespace std;
// @test([1,3,-1,-3,5,3,6,7], 3)=[3,3,5,5,6,7] 
// @test([1,-1],1)=[1,-1]
// @test([1,3,1,2,0,5],3)=[3,3,2,5]
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //单调队列
        vector<int> res;
        deque<int> dequ;
        for (int i = 0; i < nums.size(); ++i) {
            //判断双端队列中，元素个数是否超出限制
            while (!dequ.empty() && i - dequ.front() + 1 > k) dequ.pop_front();
            //保证单调性
            while (!dequ.empty() && nums[dequ.back()] < nums[i]) dequ.pop_back();
            dequ.push_back(i);
            if (k && i >= k - 1) res.push_back(nums[dequ.front()]);
        }
        return res;
    }
};