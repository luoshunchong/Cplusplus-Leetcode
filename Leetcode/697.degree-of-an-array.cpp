// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem697.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
struct node{
    int start;
    int end;
    int count;
};
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = 0;
        node res;
        int ans;
        unordered_map<int, node> unmap;
        for (int i = 0; i < nums.size(); ++i) {
            if (unmap.count(nums[i])) {
                int s = unmap[nums[i]].start;
                int e = unmap[nums[i]].end;
                int c = unmap[nums[i]].count;
                unmap[nums[i]] = {s, i, c + 1};
            }
            else {
                unmap[nums[i]] = {i, i, 1};
            }
        }
        for (auto& u : unmap) {
            node t = u.second;
            if (t.count > len) {
                len = t.count;
                ans = t.end - t.start + 1;
            }
            else if (t.count == len) {
                ans = min(ans, t.end - t.start + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

