#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Partition(vector<int>& nums, int left, int right) {
    int flag = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= flag) right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= flag) left++;
        nums[right] = nums[left];
    }
    nums[left] = flag;
    return left;
}

vector<int> TOP_K1(vector<int>& nums, int K, int left, int right) {
    //采用快排的方式
    int mid = Partition(nums, left, right);
    if (mid > left) TOP_K1(nums, K, left, mid - 1);
    if (mid < right) TOP_K1(nums, K, mid + 1, right);
    
    return vector<int> (nums.end() - K, nums.end());
}

vector<int> TOP_K2(vector<int>& nums, int K, int left, int right) {
    //采用冒泡排序的方式
    for (int i = 0; i < K; ++i) { //趟数
        for (int j = 1; j < nums.size(); ++j) { //冒泡操作
            if (nums[j] < nums[j - 1]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
    return vector<int> (nums.end() - K, nums.end());
}

vector<int> TOP_K3(vector<int>& nums, int K, int left, int right) {
    //采用优先队列（堆排序）构建小顶堆
    priority_queue<int, vector<int>, greater<int> > pqu;
    for (int i = 0; i < nums.size(); ++i) {
        if (i < K) {
            pqu.push(nums[i]);
        }
        else {
            if (pqu.top() < nums[i]) {
                pqu.pop();
                pqu.push(nums[i]);
            }
        }
    }
    vector<int> res;
    while (!pqu.empty()) {
        res.push_back(pqu.top());
        pqu.pop();
    }
    return res;
}

vector<int> TOP_K4(vector<int>& nums, int K, int left, int right) {
    //采用Partition方法，时间复杂度O(n)
    int mid = Partition(nums, left, right);
    if (mid == K) {
        return vector<int> (nums.end() - K, nums.end());
    }
    else if (mid > K) return TOP_K4(nums, K, left, mid - 1);
    else return TOP_K4(nums, K, mid + 1, right);
}

//求TOP_K个数
int main() {
    vector<int> nums = {2,1,7,9,4,3};
    int K = 5;

    vector<int> test1 = nums;
    vector<int> res1 = TOP_K1(test1, K, 0, test1.size() - 1);
    cout << "快速排序" << endl;
    for (int i = 0; i < res1.size(); ++i) {
        cout << res1[i] ;
    }
    cout << endl;

    vector<int> test2 = nums;
    vector<int> res2 = TOP_K2(test2, K, 0, test2.size() - 1);
    cout << "冒泡排序" << endl;
    for (int i = 0; i < res2.size(); ++i) {
        cout << res2[i] ;
    }
    cout << endl;

    vector<int> test3 = nums;
    vector<int> res3 = TOP_K3(test3, K, 0, test3.size() - 1);
    cout << "优先队列（堆排序）" << endl;
    for (int i = 0; i < res3.size(); ++i) {
        cout << res3[i] ;
    }
    cout << endl;

    vector<int> test4 = nums;
    vector<int> res4 = TOP_K4(test4, K, 0, test4.size() - 1);
    cout << "Partition方法" << endl;
    for (int i = 0; i < res4.size(); ++i) {
        cout << res4[i] ;
    }
    return 0;
}