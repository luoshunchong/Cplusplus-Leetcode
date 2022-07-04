#include <iostream>
#include <vector>

using namespace std;

/*
将一个数组中所有0放到数组末尾，数组中其他元素顺序不变。要求时间复杂度O(n),空间复杂度O(1)
*/

vector<int> solve(vector<int>& nums) {
    //采用双指针
    int left = 0;
    bool flag = true;
    for (int i = 0; i < nums.size(); ++i) {
        if (flag && nums[i] == 0) {
            left = i;
            flag = false;
        }
        if (nums[left] == 0 && nums[i]) {
            swap(nums[left], nums[i]);
            left++;
        }
    }
    return nums;
}

int main() {
    vector<int> nums = {3,2,5,0,2,0,0,9,0,7};
    vector<int> res = solve(nums);
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}