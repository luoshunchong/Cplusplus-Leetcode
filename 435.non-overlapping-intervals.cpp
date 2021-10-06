// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem435.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            return a[1]<b[1];
        });
        int total=0,pre=intervals[0][1];
        for(int i=1;i<n;++i){
            if(intervals[i][0]<pre) ++total;
            else pre=intervals[i][1];
        }
        return total;
    }
};
// @lc code=end

