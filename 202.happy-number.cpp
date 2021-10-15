// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    //利用一个set集合判断是否是死循环
    unordered_set<int> se;
    bool isHappy(int n) { //递归
        se.insert(n);
        if(n==1) return true;
        int sum = 0;
        while(n!=0){
            int r = n % 10;
            n = n/10;
            sum += r*r;
        }
        if (se.find(sum)!=se.end()) return false;//说明这个sum已经出现在set集合里边，这个时候发生了死循环
        bool b = isHappy(sum);
        return b;
    }
};
// @lc code=end

