/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> ve;
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return res;
    }
    //回溯
    void backtracking(string s, int pos)
    {
        if (pos >= s.size())
        {
            res.push_back(ve);
            return;
        }
        for (int i = pos; i < s.size(); ++i)
        {
            if (Is_Palindrome(s, pos, i))
            {
                string str = s.substr(pos, i - pos + 1);
                ve.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);
            ve.pop_back();
        }
    }
    //判断是否是回文子串
    bool Is_Palindrome(string t, int pos, int i)
    {
        while (pos <= i)
        {
            if (t[pos] == t[i])
            {
                pos++;
                i--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
