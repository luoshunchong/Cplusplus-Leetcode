#include <iostream>
#include <vector>
#include <algorithm>
#include "config.h"

using namespace std;

/*
冒泡排序
*/
vector<int> bubbleSort(vector<int>& nums) {
    //趟数
    //这个循环减一，有么有其实无所谓，因为最后一趟只剩下一个数肯定是有序的。
    for (int i = 0; i < nums.size() - 1; ++i) {
        //比较的次数
        //这个循环的减一，必须要有。因为nums[j + 1]要取后一位，所以不能只能到末尾的前一位。
        for (int j = 0; j < nums.size() - i - 1; ++j) {
            if (nums[j + 1] < nums[j]) {  //小于号表示顺序，大于号表示逆序
                //交换
                // swap(nums[j + 1], nums[j]);
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    return nums;
}

int main() {
    //构建测试用例
    vector<int> nums = buildTestCase(5);

    //打印排序前的数组
    cout << "打印排序前的数组:" ;
    printArray(nums);

    //排序算法实现
    vector<int> sortNums = bubbleSort(nums);
    
    //打印排序后的数组
    cout << "打印排序后的数组:";
    printArray(sortNums);
    return 0;
}