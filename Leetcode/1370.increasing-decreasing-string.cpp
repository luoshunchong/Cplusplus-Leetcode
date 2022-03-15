/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 */

// @lc code=start
class Solution {
public:
    string sortString(string s) {
        int num[26];
        string str = "";
        fill(num, num + 26, 0);
        for (int i = 0; i < s.length(); i++)
        { //遍历整个字符串，记录下每个字符串出现的次数
            num[s[i] - 'a']++;
        }
        int flag;
        while (flag!=0)
        {
            flag = 0;
            for (int i = 0; i < 26; i++)
            {
                if (num[i] != 0)
                {
                    flag = 1;
                    str += ('a' + i);
                    num[i]--;
                }
            }

            
            for (int i = 25; i >= 0; i--)
            {
                if (num[i] != 0)
                {
                    str += ('a' + i);
                    num[i]--;
                }
            }
        }
        return str;
    }
};
// @lc code=end

