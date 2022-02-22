#include <iostream>
#include <vector>
#include <algorithm>
#include "config.h"

using namespace std;

/*
希尔排序
*/
vector<int> shellSort(vector<int> &nums) {
    int j;
    for (int dk = nums.size() / 2; dk >= 1; dk /= 2) {  //dk表示步长
        for (int i = dk +1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - dk]) {
                int temp = nums[i];
                for (j = i - dk; j > 0 && temp < nums[j]; j -= dk) {
                    nums[j + dk] = nums[j];
                }
                nums[j + dk] = temp;
            }
        }
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
    vector<int> sortNums = shellSort(nums);

    //打印排序后的数组
    cout << "打印排序后的数组:";
    printArray(sortNums);
    return 0;
}