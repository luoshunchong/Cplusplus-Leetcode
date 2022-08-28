#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mod = 100000007;
int res = 0;
vector<int> temp;
void backtracking(vector<int>& nums, vector<bool>& used) {
    if (temp.size() == nums.size()) {
        res++;
        res %= mod;
        return ;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
        temp.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, used);
        temp.pop_back();
        used[i] = false;
    }
}
void check(int n) {
    if (n < 6) {
        cout << 0 << endl;
        return ;
    }
    if (n == 6) {
        cout << 1 << endl;
        return ;
    }
    int m = n - 6 + 2;
    vector<int> nums(m);
    for (int i = 0; i < m; ++i) {
        if (i == 1) nums[i] = 0;
        else nums[i] = i;
    }
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    cout << (res) % mod << endl;
}

int main() {
    int n;
    cin >> n;
    check(n);
    return 0;
}