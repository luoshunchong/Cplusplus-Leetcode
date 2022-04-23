#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    string temp = "";
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        bracktracking(n, 0);
        return res;
    }
    void bracktracking(int n, int pos) {
        if (temp.size() == n * 2) {
            if (check(temp)) {
                res.push_back(temp);
            }
            return;
        }
        

        for (int i = 0; i < 2; ++i) {
            if (i == 0) temp.push_back('(');
            if (i == 1) temp.push_back(')');
            bracktracking(n, pos + 1);
            temp.pop_back();
        }
    }

    bool check(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(s[i]);
            else {
                if (!st.empty() && st.top() == '(') st.pop();
                else return false;
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

int main() {
    int n = 3;
    Solution a;
    vector<string> res = a.generateParenthesis(n);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}