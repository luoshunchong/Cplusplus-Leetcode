// #include <iostream>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     cin.ignore();
//     for (int i = 0; i < t; ++i) {
//         string temp;
        
//         getline(cin, temp);
//         //拆分
//         string s1, s2;
//         bool flag = false;
//         for (int j = 0; j < temp.size(); ++j) {
//             if (temp[j] == ' ') {
//                 flag = true;
//                 continue;
//             }
//             if (flag) s1.push_back(temp[j]);
//             else s2.push_back(temp[j]);
//         }
//         //开始处理
//         if (s1.size() != s2.size()) {
//             cout << "No" << endl;
//             continue;
//         }
//         vector<int> t;
//         unordered_set<char> unse;
//         for (int j = 0; j < s1.size(); ++j) {
//             if (s1[j] != s2[j]) {
//                 t.push_back(j);
//             }
//             unse.insert(s1[j]);
//         }
        
//         if (t.size() == 0) {
//             if (unse.size() < s1.size()) {
//                 cout << "Yes" << endl;
//                 continue;
//             }
//             else {
//                 cout << "No" << endl;
//                 continue;
//             }
//         }
        
//         if (t.size() != 2) {
//             cout << "No" << endl;
//             continue;
//         }
//         else {
//             if (s1[t[0]] == s2[t[1]] && s1[t[1]] == s2[t[0]]) {
//                 cout << "Yes" << endl;
//                 continue;
//             }
//             else {
//                 cout << "No" << endl;
//                 continue;
//             }
//         }
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <climits>
// #include <algorithm>

// using namespace std;

// int check(long long x) {
//     if (x % 233 == 0) x /= 233;
//     else return -1;
    
//     int res = 0;
//     while (x) {
//         int t = x % 10;
//         res += t;
//         x /= 10;
//     }
//     return res;
// }

// int main() {
//     int t;
//     cin >> t;
//     for (int i = 0; i < t; ++i) {
//         long long x;
//         cin >> x;
//         cout << check(x) << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double check(vector<double>& nums, int k) {
    sort(nums.begin(), nums.end());
    int t = k/ 2;
    int sum = 0;
    for (int i = 0; i < t; ++i) {
        sum += nums[i];
    }
    for (int i = nums.size() - 1; i >= nums.size() - t; --i) {
        sum += nums[i];
    }
    double num = sum / (double)(t * 2);
    double min_num = num, max_num = num;
    for (int i = t; i < nums.size() - t; ++i) {
        if (nums[i] > max_num) max_num = nums[i];
        if (nums[i] < min_num) min_num = nums[i];
    }
    return double(max_num - min_num);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << check(nums, k) << endl;
    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int check(vector<int>& nums, int k, int x) {
//     vector<vector<int>> max_num(k, vector<int>(2, 0));
//     for (int i = 0; i < nums.size(); ++i) {
//         max_num[i % k][0] = max(max_num[i % k][0], nums[i]);
//         max_num[i % k][1]++;
//     }
//     int op_count = 0, res = 0;
//     for (int i = 0; i < nums.size(); ++i) {
//         op_count += max_num[i % k][0] - nums[i];
//         res = max(res, max_num[i % k][0]);
//     }
//     if (op_count > x) return -1;
//     int re_op = x - op_count;
//     for (int i = 0; i < k; ++i) {
//         res = max(res, max_num[i % k][0] + re_op / max_num[i % k][1]);
//     }
//     return res;
// }

// int main() {
//     int t;
//     cin >> t;
//     for (int i = 0; i < t; ++i) {
//         int n, k, x;
//         cin >> n >> k >> x;
//         vector<int> nums(n);
//         for (int j = 0; j < n; ++j) {
//             cin >> nums[j];
//         }
//         cout << check(nums, k, x) << endl;
//     }
//     return 0;
// }