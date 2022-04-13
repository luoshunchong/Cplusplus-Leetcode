// @algorithm @lc id=100334 lang=cpp 
// @title chou-shu-lcof


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        int k = n;
        long long  temp;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        pq.push(1);
        while (k) {
            temp = pq.top();
            pq.pop();
            while (!pq.empty() && temp == pq.top()) pq.pop();
            pq.push(temp * 2);
            pq.push(temp * 3);
            pq.push(temp * 5);
            k--;
        }
        return temp;
    }
};