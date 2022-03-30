// @algorithm @lc id=4 lang=cpp 
// @title median-of-two-sorted-arrays


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,3],[2])=2.00000
// @test([1,2],[3,4])=2.50000
// @test([0,0],[-1,0,1])=0.00000
// @test([1,3],[2,7])=2.50000
// @test([1,1],[-1,1])=1.00000
// @test([],[-1,1])=0.00000
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 && nums2.size() == 0) return 0;
        double res;
        int sumNum = nums1.size() + nums2.size();
        int tar = sumNum / 2;
        //找出最大值，最小值
        int minNum = INT_MAX, maxNum = INT_MIN;
        if (nums1.size() && nums2.size()) {
            maxNum = nums1[nums1.size() - 1] > nums2[nums2.size() - 1] ? nums1[nums1.size() - 1] : nums2[nums2.size() - 1];
            minNum = nums1[0] > nums2[0] ? nums2[0] : nums1[0];
        }
        else {
            if (nums1.size()) {
                maxNum = nums1[nums1.size() - 1];
                minNum = nums1[0];
            }
            if (nums2.size()) {
                maxNum = nums2[nums2.size() - 1];
                minNum = nums2[0];
            }
        }

        if (sumNum & 1) return (double)findNum(minNum, maxNum, nums1, nums2, tar);
        else return (double)(findNum(minNum, maxNum, nums1, nums2, tar) + findNum(minNum, maxNum, nums1, nums2, tar - 1)) / 2;
    }

    int findNum(int left, int right, vector<int>& nums1, vector<int>& nums2, int tar) {
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(mid, nums1, nums2, tar)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(int mid, vector<int>& nums1, vector<int>& nums2, int tar) {
        int cnt = 0;
        for (auto num : nums1) {
            if (num <= mid) {
                cnt++;
            }
            else {
                break;
            }
        }
        for (auto num : nums2) {
            if (num <= mid) {
                cnt++;
            }
            else {
                break;
            }
        }
        return cnt > tar;
    }
};