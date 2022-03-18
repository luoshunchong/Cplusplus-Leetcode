// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem503.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        st.push(0);
        bool flag = true;
        for (int i = 1; i < nums.size(); ++i) {  
            while (!st.empty() && nums[i] > nums[st.top()]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
            if (i == nums.size() - 1 && flag) {
                i = -1;
                flag = false;
            }
        }
        return res;
    }
};
// @lc code=end

