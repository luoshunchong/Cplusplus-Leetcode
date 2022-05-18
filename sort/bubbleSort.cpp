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

vector<int> bubbleSort1(vector<int>& nums) {
    //趟数
    //这个循环减一，有么有其实无所谓，因为最后一趟只剩下一个数肯定是有序的。
    for (int i = 0; i < nums.size() - 1; ++i) {
        bool swapped = false; // 本轮执行是否有交换的标志，若无则false，若有则true
        //比较的次数
        //这个循环的减一，必须要有。因为nums[j + 1]要取后一位，所以不能只能到末尾的前一位。
        for (int j = 0; j < nums.size() - i - 1; ++j) {
            if (nums[j + 1] < nums[j]) {  //小于号表示顺序，大于号表示逆序
                //交换
                // swap(nums[j + 1], nums[j]);
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                
                swapped = true; //设置为true
            }
        }
        // 若无交换，表示当前数组已完全排序，退出大循环
        if (!swapped) break;
    }
    return nums;
}

//提前结束优化 + 冒泡界优化
vector<int> bubbleSort2(vector<int>& nums) {
    int pos = nums.size() - 1, k = -1;
    //趟数
    //这个循环减一，有么有其实无所谓，因为最后一趟只剩下一个数肯定是有序的。
    for (int i = 0; i < nums.size() - 1; ++i) {
        bool swapped = false; // 本轮执行是否有交换的标志，若无则false，若有则true
        //比较的次数
        //这个循环的减一，必须要有。因为nums[j + 1]要取后一位，所以不能只能到末尾的前一位。
        for (int j = 0; j < pos; ++j) {
            if (nums[j + 1] < nums[j]) {  //小于号表示顺序，大于号表示逆序
                //交换
                // swap(nums[j + 1], nums[j]);
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                
                swapped = true; //设置为true
                k = j;  //循环里最后一次交换的位置 j赋给pos
            }
        }
        // 若无交换，表示当前数组已完全排序，退出大循环
        if (!swapped) break;
        pos = k;
    }
    return nums;
}

int main() {
    //构建测试用例
    // vector<int> nums = buildTestCase(5);
    vector<int> nums = {9,8,0,6,3,2,9,7};

    //打印排序前的数组
    cout << "打印排序前的数组:" ;
    printArray(nums);

    //排序算法实现
    vector<int> sortNums = bubbleSort2(nums);
    
    //打印排序后的数组
    cout << "打印排序后的数组:";
    printArray(sortNums);
    return 0;
}