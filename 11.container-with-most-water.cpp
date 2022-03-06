// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int temp = min(height[left], height[right]) * (right - left);
            res = res > temp ? res : temp;
            if (height[left] > height[right]) right--;
            else left++;
        }
        return res;
    }
};
// @lc code=end

