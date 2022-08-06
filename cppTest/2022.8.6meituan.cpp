// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;

// int main() {
//   int T;
//   cin >> T;
//   int x, y;
//   for (int i = 0; i < T; ++i) {
//     cin >> x;
//     cin >> y;
//     int s, l;
//     if (x >= y) {
//       l = x;
//       s = y;
//     }
//     else {
//       l = y;
//       s = x;
//     }
//     int res = s;
//     int count = 0;
//     while ((res * 2 - count) > l) {
//       res--;
//       count++;
//     }
//     cout << res << endl;
//   }
//   return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void check(vector<int>& nums, int k) {
    vector<int> train;
    vector<int> test;
    unordered_map<int, int> unmap; // 类别， 个数
    for (auto n : nums) {
        unmap[n]++;
    }
    for (auto& u : unmap) {
        u.second = (u.second + 1) / 2;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (unmap[nums[i]] != 0) {
            train.push_back(i + 1);
            unmap[nums[i]]--;
        }
        else {
            test.push_back(i + 1);
        }
    }
    for (auto tr : train) cout << tr << " ";
    cout << endl;
    for (auto te : test) cout << te << " ";
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    check(nums, k);
    return 0;
}