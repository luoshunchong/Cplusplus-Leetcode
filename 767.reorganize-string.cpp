/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> count(26);
        string ans;
        for (int i = 0; i < S.length(); ++i)
        {
            ++count[S[i] - 'a'];
        }
        int pre = -1;
        for (int i = 0; i < S.length(); ++i)
        {
            int cur = findMax(count, pre);
            if (cur == -1)
            {
                return "";
            }
            count[cur]--;
            ans += ('a' + cur);
            pre = cur;
        }
        return ans;
    }
    int findMax(vector<int> &count, int pre)
    {
        int ans = -1;
        int max = 0;
        for (int i = 0; i < count.size(); ++i)
        { //每次会遍历完，找到当前出现次数最大的字符，返回下标，并更新当前出现的最大次数
            if (i != pre && count[i] > max)
            {
                ans = i;
                max = count[i];
            }
        }
        return ans;
    }
};
// @lc code=end

