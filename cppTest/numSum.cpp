#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printNums(vector<vector<int>>& nums) {
    for (auto n : nums) {
        for (auto num : n) {
            cout << num << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> twoSum(vector<int>& nums, int target) {
    // nums 数组必须有序
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    vector<vector<int>> res;
    while (left < right) {
        // int sum = nums[left] + nums[right];
        // int left_num = nums[left], right_num = nums[right];
        // if (sum < target) {
        //     while (left < right && nums[left] == left_num) left++;
        // } 
        // else if (sum > target) {
        //     while (left < right && nums[right] == right_num) right--;
        // } 
        // else {
        //     res.push_back({left_num, right_num});
        //     while (left < right && nums[left] == left_num) left++;
        //     while (left < right && nums[right] == right_num) right--;
        // }
        if (nums[left] + nums[right] < target) left++;
        else if (nums[left] + nums[right] > target) right--;
        else {
            res.push_back({nums[left], nums[right]});
            while (nums[left] == nums[left + 1] && left + 1 < right) left++;
            while (nums[right] == nums[right - 1] && right - 1 > left) right--;
            left++;
            right--;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, 1, 2, 2, 3};
    int target = 4;
    vector<vector<int>> res = twoSum(nums, target);
    printNums(res);
    return 0;
}