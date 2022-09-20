// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <deque>
#include "commoncppproblem239.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //单调队列
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && i - dq.back() + 1 > k) dq.pop_back();
            while (!dq.empty() && nums[dq.front()] < nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
            if (i >= k - 1) res.push_back(nums[dq.back()]);
        }
        return res;
    }
};
// @lc code=end

