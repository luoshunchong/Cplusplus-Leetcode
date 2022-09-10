// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem49.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return {};
        vector<vector<string>> res;
        unordered_map<string, vector<string>> unmap;
        string temp;
        for (auto s : strs) {
            temp = s;
            sort(temp.begin(), temp.end());
            unmap[temp].push_back(s);
        }
        for (auto u : unmap) {
            res.push_back(u.second);
        }
        return res;
    }
};
// @lc code=end

