// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem4.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    /*
    使用归并的方式，合并两个有序数组，得到一个大的有序数组。
    大的有序数组的中间位置的元素，即为中位数。
    
    先计算出已经排好序的数组temp;
    然后分为单数和双数两种情况计算中位数。
    时间复杂度：m + n
    空间复杂度：m + n
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> temp;
        //得到排序后的数组
        if (m == 0) temp = nums2;
        else if (n == 0) temp = nums1;
        else {
            int i = 0;
            int j = 0;
            while (i < m && j < n) {
                if (nums1[i] >= nums2[j]) {
                    temp.push_back(nums2[j]);
                    j++;
                }
                else {
                    temp.push_back(nums1[i]);
                    i++;
                }
            }
            while (i < m) {
                temp.push_back(nums1[i]);
                i++;
            }
            while (j < n) {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        //计算中位数
        if ((m + n) % 2 == 1) {  //单数
            return temp[(m + n - 1) / 2];
        }
        else {  //双数
            return (double)(temp[(m + n) / 2] + temp[((m + n) / 2) - 1]) / 2;
        }
    }
};
// @lc code=end

