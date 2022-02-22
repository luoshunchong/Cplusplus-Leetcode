#include <iostream>
#include <vector>
#include <algorithm>
#include "config.h"

using namespace std;

/*
选择排序
*/
vector<int> selectSort(vector<int> &nums) {
    //这个循环减一的原因是，最后一个肯定是有序的，所以没有必要对最后一个再排序
    for (int i = 0; i < nums.size() - 1; ++i) {
        //选出最小的下标
        int minIndex = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[minIndex] > nums[j]) {
                minIndex = j;
            }
            //交换位置
            if (minIndex != i) {
                swap(nums[minIndex], nums[i]);
            }
        }
    }
    return nums;
}

int main() {
    //构建测试用例
    vector<int> nums = buildTestCase(5);

    //打印排序前的数组
    cout << "打印排序前的数组:";
    printArray(nums);

    //排序算法实现
    vector<int> sortNums = selectSort(nums);

    //打印排序后的数组
    cout << "打印排序后的数组:";
    printArray(sortNums);
    return 0;
}