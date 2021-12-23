#include <iostream>
#include <vector>

using namespace std;

void coinChangeII(vector<int> &coins, int amout) {
    vector<int> dp(amout + 1, 0);
    dp[0] = 1;
    // for (int i = 0; i < coins.size(); ++i) {  //遍历物品
    //     cout << "coins[" << i << "]加入遍历：";
    //     for (int j = coins[i]; j <= amout; ++j) {  //遍历背包
    //         dp[j] += dp[j - coins[i]];
    //         //打印出dp数组
    //         cout << "'" << j << "':" << dp[j] << "  ";
    //     }
    //     cout << "\n" ;
    // }

    for (int j = 0; j <= amout; j++) { // 遍历背包容量
        for (int i = 0; i < coins.size(); i++) { // 遍历物品
            if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
        }
    }
    
    cout << "" << dp[amout] << endl;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amout = 5;
    coinChangeII(coins, amout);
    // system("pause");
    return 0;
}