// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem264.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int k = n;
        int temp;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        pq.push(1);
        while (k) {
            temp = pq.top();
            pq.pop();
            if (temp == pq.top()) pq.pop();
            pq.push(temp * 2);
            pq.push(temp * 3);
            pq.push(temp * 5);
            k--;
        }
        return temp;
    }
};
// @lc code=end

