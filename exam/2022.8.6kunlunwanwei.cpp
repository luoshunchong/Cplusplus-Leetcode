#include <iostream>
#include <vector>

using namespace std;

/*
第一题，最长波动数组的长度
*/
int check(vector<int>& nums) {
    int len = nums.size();
    int up = 1, down = 1;
    int ans = 1;
    for (int i = 1; i < len; ++i) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
            down = 1;
        }
        else if (nums[i] < nums[i - 1]) {
            down = up + 1;
            up = 1;
        }
        else up = down = 1;
        ans = max(ans, max(up, down));
    }
    return ans;
}

int main() {

    return 0;
}