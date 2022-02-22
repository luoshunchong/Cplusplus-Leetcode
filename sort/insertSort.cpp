#include <iostream>
#include <vector>
#include <algorithm>
#include "config.h"

using namespace std;

/*
插入排序
*/
vector<int> insertSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int temp = nums[i];
        //移出空位
        while (i > 0 && temp < nums[i - 1]) {
            nums[i] = nums[i - 1];
            --i;
        }
        nums[i] = temp;
    }
    return nums;
}

int main() {
    //构建测试用例
    vector<int> nums = buildTestCase(8);

    //打印排序前的数组
    cout << "打印排序前的数组:";
    printArray(nums);

    //排序算法实现
    vector<int> sortNums = insertSort(nums);

    //打印排序后的数组
    cout << "打印排序后的数组:";
    printArray(sortNums);
    return 0;
}