#include<iostream>
#include<vector>

using namespace std;

void test_ZeroOne_bag_two_dimensional(vector<int> &weight, vector<int> &value, int bagSize) {
    /*
    dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少
    */
    //初始化
    vector<vector<int>> dp(weight.size(), vector<int> (bagSize + 1, 0));//全部初始化为0就可以了
    for (int j = weight[0]; j <= bagSize; ++j) {
        dp[0][j] = value[0];
    }
    //不论先遍历物品还是背包都可以
    for (int i = 1;i < weight.size(); ++i) {  //遍历物品
        for (int j = 0; j <= bagSize; ++j) {  //遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << "二维数组dp中背包所能装的最大价值总和是：" << dp[weight.size() - 1][bagSize] << endl;
}

void test_ZeroOne_bag_one_dimensional(vector<int> &weight, vector<int> &value, int bagSize) {
    /*
    dp[j]表示：容量为j的背包，所背的物品价值可以最大为dp[j]。
    */
   //初始化
   vector<int> dp(bagSize + 1, 0);  //全部初始化为0就可以了
   for (int i = 0; i < weight.size(); ++i) {  //遍历物品
       for (int j = bagSize; j >= weight[i]; --j) {  //遍历背包
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
       }
   }
   cout << "一维数组dp中背包所能装的最大价值总和是：" << dp[bagSize] << endl;
}

void test_complete_bag_first_goods(vector<int> &weight, vector<int> &value, int bagSize) {
    //先遍历物品再遍历背包
    vector<int> dp(bagSize + 1, 0);
    for (int i = 0; i < weight.size(); ++i) {  //遍历物品
        for (int j = weight[i]; j <= bagSize; ++j) {  //遍历背包容量，从小到大
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << "完全背包先遍历物品再遍历背包时，背包所能装的最大价值总和是：" << dp[bagSize] << endl;
}

void test_complete_bag_first_bag(vector<int> &weight, vector<int> &value, int bagSize) {
    //先遍历背包再遍历物品
    vector<int> dp(bagSize + 1, 0);
    for (int j = 0; j <= bagSize; ++j) {
        for (int i = 0; i < weight.size(); ++i) {
            if (j - weight[i] >= 0) dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << "完全背包先遍历背包再遍历物品时，背包所能装的最大价值总和是：" << dp[bagSize] << endl;
}

// for循环遍历物品,递归终止条件是背包被装满
// 时间复杂度O(2^n)
int weight_fin = 0 ; //装的物品重量
int value_fin = 0; // 存储中间价值
int res = 0; // 最大价值
void backtracking(vector<int> &weight, vector<int> &value, int bagSize, int pos) {
    if (weight_fin > bagSize) return ;
    res = max(res, value_fin);
    for (int i = pos; i < weight.size(); ++i) {
        weight_fin += weight[i];
        value_fin += value[i];
        backtracking(weight, value, bagSize, i + 1);
        weight_fin -= weight[i];
        value_fin -= value[i];
    }
}

int main() {
    /*
           重量  价值
    物品0   1     15
    物品1   3     20
    物品2   4     30
    */
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagsize = 4;
    //0-1背包
    //暴力解法（回溯法）
    backtracking(weight, value, bagsize, 0);
    cout << "回溯法暴力得到的最大价值:" << res << endl;
    
    //二维数组的情况
    test_ZeroOne_bag_two_dimensional(weight, value, bagsize);
    //一维数组情况
    test_ZeroOne_bag_one_dimensional(weight, value, bagsize);

    //完全背包
    test_complete_bag_first_goods(weight, value, bagsize);
    test_complete_bag_first_bag(weight, value, bagsize);

    

    // system("pause");
    return 0;
}