// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem668.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(mid, m, n, k)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    //
    bool check(int mid, int m, int n, int k) {
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            cnt += min(mid / i, n);
        }
        return cnt >= k;
    }
};
// @lc code=end

