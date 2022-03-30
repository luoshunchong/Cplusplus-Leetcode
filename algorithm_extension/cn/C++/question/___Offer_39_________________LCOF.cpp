// @algorithm @lc id=100310 lang=cpp 
// @title shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1, 2, 3, 2, 2, 2, 5, 4, 2])=2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (num == nums[i]) {
                count++;
            }
            else {
                count--;
            }
            if (count == 0) {
                num = nums[i];
                count = 1;
            }
        }
        return num;
    }
};