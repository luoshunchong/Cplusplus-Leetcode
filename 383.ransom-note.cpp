/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> ma;
        for (int i = 0; i < magazine.size(); ++i)
        {
            ma[magazine[i]]++;
        }
        for (char c : ransomNote)
        {
            if (ma.find(c) == ma.end() || ma[c] == 0)
            {
                return false;
            }
            else
            {
                ma[c]--;
            }
        }
        return true;
    }
};
// @lc code=end
