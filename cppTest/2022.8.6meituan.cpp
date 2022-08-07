#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// /*
// 第一题，点心分组
// */

// int main() {
//     int T;
//     cin >> T;
//     int x, y;
//     for (int i = 0; i < T; ++i) {
//         cin >> x;
//         cin >> y;
//         int minx = min(x, y);
//         int total = x + y;
//         while (3 * minx > total) minx--;
//         cout << minx << endl;
//     }
//     return 0;
// }

/*
第二题，分割数组
*/
// int check(vector<int>& nums) {
//     //常规方法AC
//     vector<int> num_left(nums.size() + 1, 0), num_right(nums.size() + 1, 0);
//     int res = 0x3f3f3f3f;
//     for (int i = 0; i < nums.size(); ++i) {
//         num_left[i + 1] = num_left[i] + (nums[i] >= 0);
//     }
//     for (int i = nums.size() - 1; i >= 0; --i) {
//         num_right[i] = num_right[i + 1] + (nums[i] <= 0);
//     }
//     for (int i = 0; i <= nums.size(); ++i) {
//         res = min(res, num_left[i] + num_right[i]);
//     }
//     return res;
// }
// int check1(vector<int>& nums) {
//     //前缀和
//     vector<int> num_sum(nums.size() + 1, 0);
//     for (int i = 0; i < nums.size(); ++i) {
//         num_sum[i + 1] += num_sum[i] + nums[i];
//     }

// }
// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n, 0);
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }
//     int res = check(nums);
//     return 0;
// }

/*
第三题，硬币翻转
*/
int check(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    unordered_map<int, int> unmap1; // 数字，出现的次数
    unordered_map<int, int> unmap2;
    for (int i = 0; i < n; ++i) {
        unmap1[nums1[i]]++;
        if (unmap1[nums1[i]] >= (n / 2)) return 0;
        if (nums1[i] != nums2[i]) unmap2[nums2[i]]++;
    }
    int res = 0x3f3f3f3f;
    for (auto e : unmap2) {
        if (unmap1[e.first] + e.second >= (n / 2)) {
            res = min(res, (n + 1) / 2 - unmap1[e.first]);
        }
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums1(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }
    vector<int> nums2(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }
    int res = check(nums1, nums2);
    return 0;
}
/*
第四题，数据拆分
*/
// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// void check(vector<int>& nums, int k) {
//     vector<int> train;
//     vector<int> test;
//     unordered_map<int, int> unmap; // 类别， 个数
//     for (auto n : nums) {
//         unmap[n]++;
//     }
//     for (auto& u : unmap) {
//         u.second = (u.second + 1) / 2;
//     }
//     for (int i = 0; i < nums.size(); ++i) {
//         if (unmap[nums[i]] != 0) {
//             train.push_back(i + 1);
//             unmap[nums[i]]--;
//         }
//         else {
//             test.push_back(i + 1);
//         }
//     }
//     for (auto tr : train) cout << tr << " ";
//     cout << endl;
//     for (auto te : test) cout << te << " ";
//     cout << endl;
// }

// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> nums;
//     for (int i = 0; i < n; ++i) {
//         int t;
//         cin >> t;
//         nums.push_back(t);
//     }
//     check(nums, k);
//     return 0;
// }