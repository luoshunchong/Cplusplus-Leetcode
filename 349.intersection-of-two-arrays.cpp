/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> res;
    //     unordered_set<int> se;
    //     unordered_set<int> se1;//避免重复
    //     for(int i=0;i<nums1.size();++i){
    //         se.insert(nums1[i]);
    //     }
    //     for(int j=0;j<nums2.size();++j){
    //         if(se.find(nums2[j])!=se.end()){
    //             se1.insert(nums2[j]);
    //         }
    //     }
    //     for(const int & n:se1){
    //         res.push_back(n);
    //     }
    //     return res;
    // }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {//原理和上面的一样，代码更加简洁
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
// @lc code=end

