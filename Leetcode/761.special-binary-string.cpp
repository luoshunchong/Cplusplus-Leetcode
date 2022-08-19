// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem761.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=761 lang=cpp
 *
 * [761] Special Binary String
 */

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() == 0) return "";
        vector<string> subs;
        int left = 0, count = 0;
        for (int i = 0; i < s.size(); ++i) {
            s[i] == '1' ? count++ : count--;
            if (count == 0) {
                string sub = "1";
                sub += makeLargestSpecial(s.substr(left + 1, i - left - 1));
                sub += '0';
                subs.push_back(sub);
                left = i + 1;
            }
        }
        sort(subs.begin(), subs.end(), greater<string>());
        string res = "";
        for (auto s : subs) {
            res += s;
        }
        return res;
    }
};
// @lc code=end

