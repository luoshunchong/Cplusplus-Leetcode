#include <iostream>
#include <vector>

using namespace std;

int check(vector<int>& nums, int m) {
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < nums.size(); ++i) { //遍历物品
        for (int j = nums[i]; j <= m; ++j) { //遍历背包容量
            if (dp[j - nums[i]] != INT_MAX) 
                dp[j] = min(dp[j], dp[j - nums[i]] + 1);
        }
    }
    if (dp[m] == INT_MAX) return -1;
    return dp[m];
}

int main() {
    vector<int> nums = {1, 3, 7, 11, 13};
    int m = 30;
    cout << check(nums, m) << endl;
    return 0;
}