#include <iostream>
#include <vector>

using namespace std;

int getMaxSumSeven(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(2));
    dp[0][0] = nums[0] % 7 == 0 ? nums[0] : 0;
    dp[0][1] = nums[0] % 7 == 0 ? 0 : nums[0];
    int res = dp[0][0];
    for (int i = 1; i < nums.size(); ++i) {
        dp[i][0] = max({dp[i - 1][0] + nums[i], })
        
    }
}

int main() {
    vector<int> nums = {3, 4, -7, 5, 2};
    int res = getMaxSumSeven(nums);
    cout << res << endl;
    return 0;
}