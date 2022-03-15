// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size=ratings.size();
        int sum=0;
        vector<int> res(size,1);
        for(int i=1;i<size;++i){
            if(ratings[i-1]<ratings[i]){
                res[i]=res[i-1]+1;
            }
        }
        for(int j=size-2;j>=0;--j){
            if(ratings[j]>ratings[j+1]&&res[j]<=res[j+1]){
                res[j]=res[j+1]+1;
            } 
        }
        for(int t=0;t<size;++t){
            sum+=res[t];
        }
        return sum;
    }
};
// @lc code=end

