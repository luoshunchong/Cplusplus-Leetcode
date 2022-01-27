// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem151.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    /*
    使用栈，遍历一遍，以空格为单位。
    */
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        string res;
        //这里让 i <= s.size()是为了可以更好的判断最后一个词输入到栈中
        for (int i = 0; i <= s.size(); ++i) {
            //以空字符串来判断词的界限
            if (s[i] == ' ' || i == (s.size())) {
                if (temp != "") st.push(temp);
                temp = "";
            }
            else {
                temp.push_back(s[i]);
            }
        }
        //出栈，反转
        while (!st.empty()) {
            res.append(st.top());
            st.pop();
            if (!st.empty()) {
                res.append(" ");
            }
        }
        return res;
    }
};
// @lc code=end

