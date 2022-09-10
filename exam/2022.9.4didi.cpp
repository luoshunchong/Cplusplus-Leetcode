#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double check1(vector<int>& nums, int index) {
    int sum = 0;
    for (int i = 0; i < index; ++i) {
        sum += nums[i];
    }
    return (double)sum / index;
}

int check(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<int> presum(nums.size() + 1);
    for (int i = 1; i <= nums.size(); ++i) {
        presum[i] = presum[i - 1] + nums[i - 1];
    }
    int n = nums.size();
    while (n) {
        int sum = presum[n] - presum[0];
        double t = (double)sum / n;
        if ((k * t) >= nums[n - 1]) return n;
        else {
            n--;
        }
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << check(nums, k) << endl;
    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int check(int left, int right, int num) {
//     int res = 0;
//     while (left <= right) {
//         int t = left;
//         int t1 = 0;
//         while (t) {
//             t1 ^= t % 10;
//             t /= 10;
//         }
//         if (t1 == num) res++;
//         left++;
//     }
//     return res;
// }

// int main() {
//     int T;
//     cin >> T;
//     vector<vector<int>> nums(T, vector<int>(3, 0));
//     for (int i = 0; i < T; ++i) {
//         cin >> nums[i][0];
//     }
//     for (int i = 0; i < T; ++i) {
//         cin >> nums[i][1];
//     }
//     for (int i = 0; i < T; ++i) {
//         cin >> nums[i][2];
//     }
//     for (int i = 0; i < T; ++i) {
//         cout << check(nums[i][0], nums[i][1], nums[i][2]) << " ";
//     }

//     return 0;
// }
