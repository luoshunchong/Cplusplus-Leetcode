


/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c =0？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 满足要求的三元组集合为：
[
 [-1, 0, 1],
 [-1, -1, 2]
 ]


典型数组：
nums = [-1, 0, 1, 2,  -4，6，-3，-3]，
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> check(vector<int>& nums) {
    if (nums.size() < 3) return {};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) right--;
            else if (nums[i] + nums[left] + nums[right] < 0) left++;
            else {
                res.push_back({nums[i], nums[left], nums[right]});
                while (nums[left] == nums[left + 1] && left + 1 < right) left++;
                while (nums[right] == nums[right - 1] && right - 1 > left) right--;
                left++;
                right--;
            }
        }
    }
    return res;
}



int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4, 5, 4, 6, 1};
    vector<vector<int>> res = check(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout << "[" << res[i][0] << "," << res[i][1] << "," << res[i][2] << "]" << endl;
    }
    return 0;
}