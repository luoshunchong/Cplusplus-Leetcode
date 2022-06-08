// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include "config.h"

// using namespace std;

// void printArray(vector<int>& nums) {
//     for (auto a : nums) {
//         cout << a << " ";
//     }
//     cout << endl;
// }

// // 为了统一操作, 堆存储在 顺序数组中, 下标从 1 开始, 以大根堆为例

// //向下调整堆算法
// void AdjustDown(vector<int>& A, int k, int len) {
//     //函数AdjustDown将元素k向下进行调整
//     A[0] = A[k]; // A[0]暂存
//     for (int i = 2 * k; i <= len; i *= 2) {  //沿key较大的子结点向下筛选
//         if (i < len && A[i] < A[i + 1]) i++;  //取key较大的子结点的下标
//         if (A[0] >= A[i]) break;  //筛选结束
//         else {
//             A[k] = A[i];  //将A[i]调整到双亲结点上
//             k = i;		//修改k值，以便继续向下筛选
//         }
//     }
//     A[k] = A[0];    //被筛选结点的值放入最终位置
// }

// //向上调整堆算法
// void AdjustUp(vector<int>& A, int k) {
//     //参数k为向上调整的结点，也为堆的元素个数
//     A[0] = A[k];
//     int i = k / 2;  //若结点值大于双亲结点，则将双亲结点向下调，并继续向上比较
//     while (i > 0 && A[i] < A[0]) {  //循环跳出条件
//         A[k] = A[i];		//双亲结点下调
//         k = i;
//         i = k / 2;		//继续向上比较
//     }
//     A[k] = A[0];		//调整到最终位置
// }

// //大根堆的建立
// void BuildMaxHeap(vector<int>& A, int len) {
//     for (int i = len / 2; i >= 1; i--) {
//         AdjustDown(A, i, len);
//     }
// }

// /*
// 堆排序
// */
// vector<int> heaptSort(vector<int> &nums) {
//     BuildMaxHeap(nums, nums.size());		  //初始建堆
//     for (int i = nums.size(); i >= 1; --i) {   //n - 1趟的交换和建堆过程
//         swap(nums[i], nums[1]);		  //输出堆顶元素（和堆低元素交换）
//         AdjustDown(nums, 1, i - 1);  //整理，把剩余的i - 1个元素整理成堆
//     }
//     return nums;
// }

// int main() {
//     //构建测试用例
//     // vector<int> nums = buildTestCase(8);
//     vector<int> nums = {-999,8,0,6,3,2,9,7};

//     //打印排序前的数组
//     cout << "打印排序前的数组:";
//     printArray(nums);

//     //排序算法实现
//     vector<int> sortNums = heaptSort(nums);

//     //打印排序后的数组
//     cout << "打印排序后的数组:";
//     printArray(sortNums);
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include "config.h"

using namespace std;

void printArray(vector<int>& nums) {
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;
}

//向下调整堆算法
void AdjustDown(vector<int>& A, int k, int len) {
    //函数AdjustDown将元素k向下进行调整
    int temp = A[k]; // A[0]暂存
    for (int i = 2 * k + 1; i < len; i = 2 * i + 1) {  //沿key较大的子结点向下筛选
        if (i + 1 < len && A[i] < A[i + 1]) i++;  //取key较大的子结点的下标
        if (temp >= A[i]) break;  //筛选结束
        else {
            A[k] = A[i];  //将A[i]调整到双亲结点上
            k = i;		//修改k值，以便继续向下筛选
        }
    }
    A[k] = temp;    //被筛选结点的值放入最终位置
}

//向上调整堆算法
void AdjustUp(vector<int>& A, int k) {
    //参数k为向上调整的结点，也为堆的元素个数,相当于数组最后一个元素的下标
    int temp = A[k];
    int i = (k - 1) / 2;  //若结点值大于双亲结点，则将双亲结点向下调，并继续向上比较
    while (k > 0 && A[i] < temp) {  //循环跳出条件
        A[k] = A[i];		//双亲结点下调
        k = i;
        i = (k - 1) / 2;		//继续向上比较
    }
    A[k] = temp;		//调整到最终位置
}

//大根堆的建立
void BuildMaxHeap(vector<int>& A, int len) {
    for (int i = (len - 1) / 2; i >= 0; --i) {
        AdjustDown(A, i, len);
    }
}

/*
堆排序
*/
vector<int> heaptSort(vector<int> &nums) {
    BuildMaxHeap(nums, nums.size());		  //初始建堆
    for (int i = nums.size() - 1; i >= 0; --i) {   //n - 1趟的交换和建堆过程
        swap(nums[i], nums[0]);		  //输出堆顶元素（和堆底元素交换）
        AdjustDown(nums, 0, i);       //整理，把剩余的i个元素整理成堆
    }
    return nums;
}

int main() {
    //构建测试用例
    // vector<int> nums = buildTestCase(8);
    vector<int> nums = {-9,8,0,6,3,2,9,7};

    //打印排序前的数组
    cout << "打印排序前的数组:";
    printArray(nums);

    //排序算法实现
    vector<int> sortNums = heaptSort(nums);

    //打印排序后的数组
    cout << "打印排序后的数组:";
    printArray(sortNums);
    return 0;
}