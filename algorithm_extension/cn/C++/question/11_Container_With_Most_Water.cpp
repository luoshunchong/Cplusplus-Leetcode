// @algorithm @lc id=11 lang=cpp 
// @title container-with-most-water


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,8,6,2,5,4,8,3,7])=49
// @test([1,1])=1
class Solution {
public:
    int maxArea(vector<int>& height) {
        //使用双指针
        int sum = 0;
        int left = 0, right = height.size() - 1;
        while (left <= right) {
            sum = max(sum, min(height[left], height[right]) * (right - left));
            if (height[left] > height[right]) right--;
            else left++;
        }
        return sum;
    }
};