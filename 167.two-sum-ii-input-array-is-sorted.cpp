// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem167.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left=0,right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if(numbers[left]+numbers[right]>target) --right;
            else{
                ++left;
            }
        }
        return res;
    }
};
// @lc code=end

