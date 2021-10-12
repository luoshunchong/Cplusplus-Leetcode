/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    // vector<int> sortedSquares(vector<int> &nums)
    // {//O(nlogn)
    //     vector<int> res;
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         res.push_back(pow(nums[i], 2));
    //     }
    //     sort(res.begin(), res.end());
    //     return res;
    // }

    vector<int> sortedSquares(vector<int> &nums)
    { //时间复杂度O(n),双指针
        vector<int> res(nums.size(), 0);
        int i=0;
        int j = nums.size() - 1;
        int k = j;
        while(i<=j)
        {
            if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                res[k--] = nums[j] * nums[j];
                --j;
            }
            else
            {
                res[k--] = nums[i] * nums[i];
                ++i;
            }
        }
        return res;
    }
};
// @lc code=end
