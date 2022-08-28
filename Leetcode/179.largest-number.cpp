// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem179.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const int a, const int b) {
        string stra = to_string(a);
        string strb = to_string(b);
        return stra + strb > strb + stra;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for (auto num : nums) {
            cout << num << " ";
            res += to_string(num);
        }
        if (res[0] == "0") return "0";
        return res;
    }
};
// @lc code=end

