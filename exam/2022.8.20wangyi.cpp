// #include <iostream>
// #include <string>
// #include <unordered_map>

// using namespace std;

// bool isStr(string& s) {
//     int t = 0;
//     unordered_map<char, int> unmap;
//     for (auto t : s) unmap[t]++;
//     t = unmap[s[0]];
//     for (auto u : unmap) {
//         if (u.second != t) return false;
//     }
//     return true;
// }

// void check(string& s) {
//     int res = 0;
//     //跨度
//     int len = (s.size() / 3);
//     for (int i = 1; i <= len; ++i) {
//         int len1 = (s.size() - 3 * i);
//         for (int j = 0; j <= len1; ++j) {
//             string t = s.substr(j, 3 * i);
//             if (isStr(t)) res++;
//         }
//     }
//     cout << res << endl;
// }

// int main() {
//     string s;
//     cin >> s;
//     check(s);
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// int res = 0;
// int temp = INT_MAX;
// void backtracking(vector<int>& nums, int k, int pos, int count) {
//     if (count == k) {
//         res = max(res, temp);
//         return ;
//     }
//     for (int i = pos; i < nums.size(); ++i) {
//         temp &= nums[i];
//         count++;
//         backtracking(nums, k, i + 1, count);
//         temp &= nums[i];
//         count--;
//     }
// }
// void check(vector<int>& nums, int k) {
//     // for (int i = 0; i < nums.size(); ++i) {
//     //     temp <= 1;
//     // }
//     backtracking(nums, k, 0, 0);
//     cout << res << endl;
// }


// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> nums(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }
//     check(nums, k);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>

// using namespace std;

// bool isTrue(string& s) {
//     for (int i = 1; i < s.size(); ++i) {
//         if (s[i] - '0' < s[i - 1] - '0') return false;
//     }
//     return true;
// }

// void check(string& str) {
//     unordered_map<char, int> unmap;
//     for (auto num : str) unmap[num] = 1;
//     int res = 0;
//     vector<pair<int, int>> temp;
//     queue<string> qu;
//     qu.push(str);
//     while (!qu.empty()) {
//         int len = qu.size();
//         for (int i = 0; i < len; ++i) {
//             string p = qu.front();
//             qu.pop();
//             for (int i = 0; i < p.size(); ++i) {
//                 //加一
//                 char t = p[i];
//                 char c = (t - '0') + 1 + '0';
//                 if (unmap.count(c) && unmap[c]) continue;
//                 else {
//                     unmap[c] = 1;
//                     unmap[t] = 0;
//                     p[i] = c;
//                 }
//                 for (int j = i + 1; j < p.size(); ++j) {
//                     //减一
//                     char t1 = p[j];
//                     char c1 = (t1 - '0') - 1 + '0';
//                     if (unmap.count(c1) && unmap[c1]) continue;
//                     else {
//                         unmap[c1] = 1;
//                         unmap[t1] = 0;
//                         p[i] = c1;
//                     }
//                     temp.push_back({i, j});
//                     if (isTrue(p)) {
//                         cout << res << endl;
//                         for (auto t : temp) cout << t.first << " " << t.second << endl;
//                         return ;
//                     }
//                 }
//             }
//         }
//         res++;
//     }
//     return ;
// }


// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }
//     string str = "";
//     for (auto num : nums) str += to_string(num);
//     check(str);
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool isTrue(string& s) {
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] - '0' < s[i - 1] - '0') return false;
    }
    return true;
}

void check(string& str) {
    unordered_map<char, int> unmap;
    for (auto num : str) unmap[num] = 1;
    int res = 0;
    vector<pair<int, int>> temp;
    queue<string> qu;
    qu.push(str);
    while (!qu.empty()) {
        int len = qu.size();
        for (int i = 0; i < len; ++i) {
            string p = qu.front();
            qu.pop();
            for (int i = 0; i < p.size(); ++i) {
                //加一
                char t = p[i];
                int num = (t - '0');
                if (num == 9) continue;
                char c = num + 1 + '0';
                if (unmap.count(c) && unmap[c]) continue;
                else {
                    unmap[c] = 1;
                    unmap[t] = 0;
                    p[i] = c;
                }
                for (int j = i + 1; j < p.size(); ++j) {
                    //减一
                    char t1 = p[j];
                    int num = (t1 - '0');
                    if (num == 0) continue;
                    char c1 = num - 1 + '0';
                    if (unmap.count(c1) && unmap[c1]) continue;
                    else {
                        unmap[c1] = 1;
                        unmap[t1] = 0;
                        p[j] = c1;
                    }
                    qu.push(p);
                    temp.push_back({i, j});
                    if (isTrue(p)) {
                        cout << res << endl;
                        for (auto t : temp) cout << t.first << " " << t.second << endl;
                        return ;
                    }
                    //加回来
                    unmap[c1] = 0;
                    unmap[t1] = 1;
                    p[j] = t1;
                }
                //减回来
                unmap[c] = 0;
                unmap[t] = 1;
                p[i] = t;
            }
        }
        res++;
    }
    return ;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    string str = "";
    for (auto num : nums) str += to_string(num);
    check(str);
    return 0;
}

void check(string& s) {
    int res = 0;
    //跨度
    int len = (s.size() / 3);
    for (int i = 1; i <= len; ++i) {
        int len1 = (s.size() - 3 * i);
        for (int j = 0; j <= len1; ++j) {
            string t = s.substr(j, 3 * i);
            if (isStr(t)) res++;
        }
    }
    cout << res << endl;
}