// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem88.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos=m+n-1;
        m=m-1;
        n=n-1;
        while(n>=0&&m>=0){
            if(nums2[n]>=nums1[m]){
                nums1[pos]=nums2[n];
                --pos;
                --n;
            }else{
                nums1[pos]=nums1[m];
                --pos;
                --m;
            }
        }
        while(n>=0){
            nums1[pos]=nums2[n];
            --pos;
            --n;
        }
    }
};
// @lc code=end

