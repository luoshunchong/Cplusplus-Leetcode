/*
        重量    价值
物品0    1       15
物品1    3       20
物品2    4       30
问背包能背的物品最大价值是多少？
*/

#include <iostream>
#include <vector>

using namespace std;

void printDP(vector<int>& nums) {
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int solve1(vector<int>& weight, vector<int>& value, int bagweight) {
    //0-1背包
    vector<int> dp(bagweight + 1, 0);//定义dp：容量为j的背包所能背的物品最大价值。
    //初始化
    dp[0] = 0; //背包容量为0，所能装的最大物品价值为0。
    for (int i = 0; i < weight.size(); ++i) { //先遍历物品
        for (int j = bagweight; j >= weight[i]; --j) { //再遍历背包容量,为什么背包容量要从大到小？为了保证物品只被放入一次。
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
        printDP(dp);
    }
    return dp[bagweight];
}

int main() {
    //0-1背包
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    int ans1 = solve1(weight, value, bagWeight);
    cout << "背包所能装的最大价值：" << ans1 << endl;
    return 0;
}