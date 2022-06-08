#include <iostream>
#include <vector>
#include <algorithm>
#include "config.h"

using namespace std;

void printArray(vector<int>& nums) {
    for (auto a : nums) {
        cout << a ;
    }
    cout << endl;
}


/*
插入排序
*/
vector<int> insertSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int temp = nums[i];
        //移出空位
        int j = i;
        while (j > 0 && temp < nums[j - 1]) {
            nums[j] = nums[j - 1];
            --j;
        }
        nums[j] = temp;
    }
    return nums;
}

//折半插入
vector<int> HInsertSort(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++){
        int temp = nums[i];
        // 使用二分法寻找插入的位置
        int left = 0, right = i - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > temp) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        // 二分查找之后left指向大于temp的第一个数，right指向小于temp的第一个数
        // 移出空位
        int j = i;
        while (j > left && temp < nums[j - 1]) {
            nums[j] = nums[j - 1];
            --j;
        }
        nums[j] = temp;
    }
    return nums;
}

int main() {
    //构建测试用例
    // vector<int> nums = buildTestCase(8);
    vector<int> nums = {9,8,0,6,3,2,9,7};

    //打印排序前的数组
    cout << "打印排序前的数组:";
    printArray(nums);

    //排序算法实现
    vector<int> sortNums = insertSort(nums);

    vector<int> HsortNums = HInsertSort(nums);

    //打印排序后的数组
    cout << "打印排序后的数组:";
    printArray(sortNums);

    cout << "打印折半插入排序后的数组:";
    printArray(HsortNums);
    return 0;
}