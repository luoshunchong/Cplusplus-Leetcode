#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
// #include "config.h"

using namespace std;

void printArray(vector<int>& nums) {
    for (auto a : nums) {
        cout << a ;
    }
    cout << endl;
}

int Partition (vector<int> &nums, int left, int right) {  //传入一个数组和要进行partition的范围
	
    int flag = nums[left];  // 将第一个数做为中间数
    while (left < right) {
        while (left < right && nums[right] >= flag) right--; //从右边开始寻找，找到第一个小于中间数的数
        nums[left] = nums[right]; //找到后往最左边的位置放
        while (left < right && nums[left] <= flag) left++; //同理，从最左边开始寻找，找到第一个大于中间数的数，往右边放
        nums[right] = nums[left]; //因为end的位置是之前第n个比中间数小的数，并且已经放在了靠左的位置，所以此时可以将比中间数大的数往end填
    }
    nums[left] = flag;
    return left; //返回中间值的下标
}

void sort(vector<int> &nums, int left, int right) { //将[left,right]范围内进行排序
    int mid = Partition(nums, left, right);  //在该范围进行一次partition，得到中间值的下标mid，可知此时mid对应的数以左的数比它小，以右的数比它大
    if (mid > left) sort(nums, left, mid - 1); //[l---mid--------------------r] 当mid大于范围的最小下标时，将[left,mid-1]范围内进行一次partition
    if (mid < right) sort(nums, mid + 1, right); //同理，当mid小于范围的最大下标时，将[mid+1,right]范围内进行一次partition
} //分到最后每个数的左边的数都比它本身小，右边的数都比它本身的大，也就完成了从小到大的排序。

/*
快速排序
*/
vector<int> quickSort(vector<int> &nums) {
    int left = 0;
    int right = nums.size() -  1;
    sort(nums, left, right);
    return nums;
}

vector<int> quickSort1(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = Partition(nums, left, right);
        if (mid >= left) right = mid - 1;
        else left = mid + 1;
    }
    return nums;
}
vector<int> quickSort2(vector<int>& nums) {
    stack<int> st;
    st.push(0);
    st.push(nums.size() - 1);
    while (!st.empty()) {
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        int mid = Partition(nums, left, right);
        if (mid > left) {
            st.push(left);
            st.push(mid - 1);
        }
        if (mid < right) {
            st.push(mid + 1);
            st.push(right);
        }
    }
    return nums;
}

int main() {
    //构建测试用例
    // vector<int> nums = buildTestCase(8);
    vector<int> nums = {9, 8, 0, 6, 3, 2, 9, 7};

    //打印排序前的数组
    cout << "打印排序前的数组:";
    printArray(nums);

    //排序算法实现
    vector<int> sortNums = quickSort(nums);
    vector<int> sortNums1 = quickSort1(nums);
    vector<int> sortNums2 = quickSort2(nums);

    //打印排序后的数组
    cout << "打印排序后的数组:" << endl;
    printArray(sortNums);
    printArray(sortNums1);
    printArray(sortNums2);
    return 0;
}