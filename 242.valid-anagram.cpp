/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     vector<int> a(26, 0);
    //     if (s.size() != t.size())
    //         return false;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         a[s[i] - 'a']++;
    //         a[t[i] - 'a']--;
    //     }
    //     for (int i = 0; i < 26; i++)
    //     {
    //         if (a[i] != 0)
    //             return false;
    //     }
    //     return true;
    // }

    bool isAnagram(string s, string t)
    {//哈希表
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> se;
        for(int i=0;i<s.size();++i){
            se[s[i]]++;
            se[t[i]]--;
        }
        for(auto j:se){
            if(j.second!=0) return false;
        }
        return true;
    }
};
// @lc code=end

