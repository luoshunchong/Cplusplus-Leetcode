// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem739.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // vector<int> res(temperatures.size(), 0);
        // stack<int> st;
        // st.push(0);
        // for (int i = 1; i < temperatures.size(); ++i) {
        //     while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        //         res[st.top()] = (i-st.top());
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        // return res;

        if (temperatures.size() == 0) return {};
        vector<int> res(temperatures.size());
        stack<int> st;
        st.push(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            if (temperatures[i] <= temperatures[st.top()]) st.push(i);
            else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

