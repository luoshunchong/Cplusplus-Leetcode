/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    // int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    //     //时间复杂度n*n，空间复杂度n*n
    //     map<int, int> map1, map2;
    //     int n = A.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             map1[A[i] + B[j]]++;
    //             map2[C[i] + D[j]]++;
    //         }
    //     }
    //     int res = 0;
    //     for (auto p : map1)
    //     {
    //         res += p.second * map2[-p.first];
    //     }
    //     return res;
    // }

    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        //时间复杂度n*n，空间复杂度n
        unordered_map<int,int> ma;//key:a+b的值，value存储a+b出现的次数
        for(int i=0;i<A.size();++i){
            for(int j=0;j<B.size();++j){
                ma[A[i]+B[j]]++;
            }
        }
        int res=0;
        for(int c:C){
            for(int d:D){
                if(ma.find(0-(c+d))!=ma.end()){
                    res += ma[0 - (c + d)];
                }
            }
        }
        return res;
    }
};
// @lc code=end

