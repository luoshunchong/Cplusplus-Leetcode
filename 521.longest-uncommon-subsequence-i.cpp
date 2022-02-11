/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I
 */

// @lc code=start
class Solution {
public:
    int findLUSlength(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        if (lenA != lenB) {
            return max(lenA, lenB);
        }
        else {
            if (a == b) {
                return -1;
            }
            else {
                return lenA;
            }
        }
    }
};
// @lc code=end

