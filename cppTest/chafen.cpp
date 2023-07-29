#include <iostream>
#include <vector>

using namespace std;

// 差分数组工具类
class Difference {
public:
    // 差分数组
    vector<int> diff;
    
    /* 输入一个初始数组，区间操作将在这个数组上进行 */
    Difference(vector<int>& nums) {
        diff = vector<int>(nums.size());
        // 根据初始数组构造差分数组
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    /* 给闭区间 [i, j] 增加 val（可以是负数）*/
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    /* 返回结果数组 */
    vector<int> result() {  //返回局部变量不能传引用
        vector<int> res = vector<int>(diff.size());
        // 根据差分数组构造结果数组
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    // nums 初始化为全 0
    vector<int> nums = vector<int>(length);
    // 构造差分解法
    Difference df(nums);
    
    for (vector<int>& update : updates) {
        int i = update[0];
        int j = update[1];
        int val = update[2];
        df.increment(i, j, val);
    }
    
    return df.result();
}

int main() {
    int length = 5;
    vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
    vector<int> A = getModifiedArray(length, updates);
    return 0;
}