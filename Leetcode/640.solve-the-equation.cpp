// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem640.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        //模拟
        stack<string> st;
        string t = "";
        bool flag = false;
        for (int i = 0; i < equation.size(); ++i) {
            if (equation[i] == '=') {
                flag = true;
                if (t[0] != '+' && t[0] != '-') t.insert(0, "+");
                st.push(t);
                if (equation[i + 1] != '+' && equation[i + 1] != '-') t = "-";
                else t = "";
                continue;
            }
            if (equation[i] == '+' || equation[i] == '-') {
                if (t[0] != '+' && t[0] != '-') t.insert(0, "+");
                st.push(t);
                t = "";
            }
            if ((equation[i] == '+' || equation[i] == '-') && flag)  t += equation[i] == '+' ? '-' : '+';
            else t += equation[i];
        }
        st.push(t);
        //遍历栈，开始计算
        int x_num = 0, digit_num = 0;
        while (!st.empty()) {
            string te = st.top();
            cout<< te << endl;
            st.pop();
            if (te[te.size() - 1] == 'x') {
                if (te[0] == '+') {
                    x_num += te.substr(1, te.size() - 2) == "" ? 1 : stoi(te.substr(1, te.size() - 2));
                }
                else {
                    x_num -= te.substr(1, te.size() - 2) == "" ? 1 : stoi(te.substr(1, te.size() - 2));
                }
            }
            else {
                if (te[0] == '+') {
                    digit_num += stoi(te.substr(1, te.size() - 1));
                }
                else {
                    digit_num -= stoi(te.substr(1, te.size() - 1));
                }
            }
        }
        if (x_num == 0 && digit_num != 0) return "No solution";
        else if (x_num == 0) return "Infinite solutions";
        else return "x=" + to_string((-digit_num) / x_num);
    }
};
// @lc code=end

