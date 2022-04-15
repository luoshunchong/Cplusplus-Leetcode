// @algorithm @lc id=100324 lang=cpp 
// @title he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(9)=[[2,3,4],[4,5]]
// @test(15)=[[1,2,3,4,5],[4,5,6],[7,8]]
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3) return {};
        vector<vector<int>> res;
        int left = 1, right = 2, temp = (target + 1) / 2, cursum = left + right;
        while (left < temp) {
            if (cursum == target) res.push_back(printvec(left, right));
            while (left < temp && cursum > target) {
                cursum -= left;
                left++;
                if (cursum == target) res.push_back(printvec(left, right));
            }
            right++;
            cursum += right;
        }
        return res;
    }
    vector<int> printvec(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i) {
            res.push_back(i);
        }
        return res;
    }
};