// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem85.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int>> nums(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    nums[i][j] = (j == 0 ? 1 : nums[i][j - 1] + 1);
                }
            }
        }
        int res = 0;
        vector<int> zero(matrix[0].size(), 0);
        nums.insert(nums.begin(), zero);
        nums.push_back(zero);
        for (int j = 0; j < matrix[0].size(); ++j) {
            stack<int> st;
            for (int i = 0; i < nums.size(); ++i) {
                while (!st.empty() && nums[st.top()][j] > nums[i][j]) {
                    int mid = st.top();
                    st.pop();
                    int h = i - st.top() - 1;
                    int w = nums[mid][j];
                    res = max(res, w * h);
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

