/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> map1, map2;
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map1[A[i] + B[j]]++;
                map2[C[i] + D[j]]++;
            }
        }
        int res = 0;
        for (auto p : map1)
        {
            res += p.second * map2[-p.first];
        }
        return res;
    }
};
// @lc code=end

