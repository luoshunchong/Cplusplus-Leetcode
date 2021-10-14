// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem1002.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        vector<int> minnum(26,INT_MAX);
        vector<int> num(26);
        if(words.size()==0) return res;
        for(const string& word:words){
            fill(num.begin(),num.end(),0);
            for(char ch:word){
                ++num[ch-'a'];
            }
            for(int i=0;i<26;++i){
                minnum[i] = min(minnum[i],num[i]);
            }
        }
        for(int i=0;i<26;++i){
            for(int j=0;j<minnum[i];++j){
                res.emplace_back(1,i+'a');
            }
        }
        return res;
    }
};
// @lc code=end

