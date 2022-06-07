// @algorithm @lc id=907 lang=cpp 
// @title koko-eating-bananas


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,6,7,11],8)=4
// @test([30,11,23,4,20],5)=30
// @test([30,11,23,4,20],6)=23
// @test([10],2)=5
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000 + 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(piles, h, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool check(vector<int>& piles, int h, int mid) {
        int ho = 0;
        for (auto p : piles) {
            // if (p <= mid) ho++;
            // else ho += (p / mid) + 1; //当p被mid整除的时候多加了1
            ho += p / mid;
            if (p % mid > 0) ho++;
        }
        return ho <= h;
    }
};