#include <iostream>
#include <vector>
#include <algorithm>
#include "config.h"

using namespace std;

void Merge(vector<int> &nums, int left, int mid, int right){
    //left为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i = left, j = mid + 1, k = 0;  //mid+1为第2有序区第1个元素，j指向第1个元素
    vector<int> temp(right - left + 1); // temp数组暂存合并的有序序列
    while(i <= mid && j <= right) {
        if (nums[i] <= nums[j]) //较小的先存入temp中
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    while (i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = nums[i++];
    while (j <= right)//同上
        temp[k++] = nums[j++];
    for (i = left, k = 0; i <= right; i++, k++)//将排好序的存回nums中left到right这区间
	    nums[i] = temp[k];
}

void sort(vector<int> &nums, int left,int right) {
    if(left >= right) { return; } // 终止递归的条件，子序列长度为1
    int mid =  left + (right - left) / 2;  // 取得序列中间的元素
    sort(nums, left, mid);  // 对左半边递归
    sort(nums, mid+1, right);  // 对右半边递归
    Merge(nums, left, mid, right);  // 合并
  }

/*
归并排序
*/
vector<int> mergeSort(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    sort(nums, left, right);
    return nums;
}

int main() {
    //构建测试用例
    vector<int> nums = buildTestCase(15);

    //打印排序前的数组
    cout << "打印排序前的数组:";
    printArray(nums);

    //排序算法实现
    vector<int> sortNums = mergeSort(nums);

    //打印排序后的数组
    cout << "打印排序后的数组:";
    printArray(sortNums);
    return 0;
}