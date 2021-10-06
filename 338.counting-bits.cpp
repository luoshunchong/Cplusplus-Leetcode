/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        int i=1;
        vector<int> res(num+1);
        for(int i=0;i<=num;++i){
            if(i%2==0) res[i]=res[i/2];
            else res[i]=res[i/2]+1;
        }
        return res;
    }
};
// @lc code=end

