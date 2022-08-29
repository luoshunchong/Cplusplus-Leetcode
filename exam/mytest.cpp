#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void check(vector<int>& nums) {
    unordered_map<int, int> unmap;
    for (auto num : nums) unmap[num]++;
    int res = 0;
    for (auto num : nums) {
        res = max(res, unmap[num] + unmap[num - 1] + unmap[num + 1]);
    }
    cout << res << endl;
}

int main() {

    vector<int> nums = {1,3};
    check(nums);
    return 0;
}