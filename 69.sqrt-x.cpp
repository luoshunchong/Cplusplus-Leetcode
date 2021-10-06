// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem69.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {//与数学相结合的二分查找
        if(x==0) return x;
        int left=1,right=x,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            int sum=x/mid;
            if(sum==mid) return mid;
            else if(sum>mid) right=mid-1;
            else left=mid+1;
        }
        return right;
    }
};
// @lc code=end

