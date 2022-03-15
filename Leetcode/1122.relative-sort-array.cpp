/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(), arr1.end());
        vector<int> res;
        const int m = arr1.size();
        vector<int> tmp(m,0);
        int t = 0;
        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr2[i] == arr1[j])
                {
                    res.push_back(arr1[j]);
                    tmp[j]=1;
                }
            }
        }
        for (t; t < tmp.size(); t++){
            if(tmp[t]==0) res.push_back(arr1[t]);
        }
        return res;
    }
};
// @lc code=end

