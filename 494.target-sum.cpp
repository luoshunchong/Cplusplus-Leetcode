/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        //计算总和
        for(int i=0;i<nums.size();++i) sum+=nums[i];
        //如果target的绝对值要比总和还要大的话，此时没有方案
        if(abs(target)>sum) return 0;
        //如果target和sum的总和不能被2整除，此时灭没有方案
        if((target+sum)%2==1) return 0;
        //假设要求的背包容量是bagsize，那么负数的值就是(sum-bagsize).
        //那么就有关系式S = bagsize-(sum-bagsize),其中就只有bagsize未知
        //因此就转化成了一个背包问题。即bagsize = (sum+S)/2.
        //在背包容量为bagsize的时候，最大能装的物品价值dp[bagsize].
        int bagsize = (target+sum)/2;
        //初始化dp[0]初始化为1，其他的初始化为0.
        vector<int> dp(bagsize+1,0);
        dp[0] = 1;
        //一维滚动数组的遍历方式
        for(int i=0;i<nums.size();++i){
            for(int j=bagsize;j>=nums[i];--j){
                dp[j] += dp[j-nums[i]];
                //递推公式，不考虑nums[i]的话，填满j-nums[i]的背包，总共有dp[j-nums[i]]种方法
                //画出dp数组的状态图更好理解
            }
        }
        return dp[bagsize];
    }
};
// @lc code=end

