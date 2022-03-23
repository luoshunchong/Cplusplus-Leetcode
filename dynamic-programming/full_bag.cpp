#include <iostream>
#include <vector>

using namespace std;

int full_bag1(int amount, const vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    //计算组合数
    for (int i = 0; i < coins.size(); ++i) {  //物品
        for (int j = coins[i]; j <= amount; ++j) { //背包容量
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int full_bag2(int amount, const vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    //计算排列数
    for (int i = 0; i <= amount; ++i) { // 背包容量
        for (int j = 0; j < coins.size(); ++i) { //物品
            if (j >= coins[i]) dp[i] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int main() {
    //Leetcode 518. 零钱兑换 II
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int res1 = full_bag1(amount, coins);
    int res2 = full_bag2(amount, coins);

    cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}