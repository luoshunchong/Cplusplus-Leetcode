#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Partition
int Partition (vector<int>& nums, int left, int right) {
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
//递归
vector<int> fastSort(vector<int>& nums, int left, int right) {
    int mid = Partition(nums, left, right);
    if (mid > left) fastSort(nums, left, mid - 1);
    if (mid < right) fastSort(nums, mid + 1, right);
    return nums;
}

//非递归
vector<int> fastSortNodigui(vector<int>& nums, int left, int right) {
    stack<int> st;
    st.push(left);
    st.push(right);
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
    vector<int> nums = {3,2,2,1,0,-3,-7};
    vector<int> res = fastSort(nums, 0, nums.size() - 1);
    cout << "递归实现" << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] ;
    }
    cout << endl;
    vector<int> res1 = fastSortNodigui(nums, 0, nums.size() - 1);
    cout << "非递归实现" << endl;
    for(int i = 0; i < res1.size(); ++i) {
        cout << res1[i] ;
    }
    return 0;
}
