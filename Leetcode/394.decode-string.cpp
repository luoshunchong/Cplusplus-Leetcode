// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem394.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        if (s.size() == 0) return "";
        stack<char> st;
        string res = "";

        for (int i = 0; i < s.size(); ++i) {
            string temp = "";
            if (s[i] == ']') {
                while (st.top() != '[') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string tr = "";
                while (!st.empty() && isdigit(st.top())) {
                    tr.push_back(st.top());
                    st.pop();
                }
                // cout << tr << endl;
                reverse(tr.begin(), tr.end());
                int t = stoi(tr);
                string te = "";
                for (int j = 0; j < t; ++j) {
                    te += temp;
                }
                for (int i = te.size() - 1; i >= 0; --i) st.push(te[i]);
            }
            else {
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

