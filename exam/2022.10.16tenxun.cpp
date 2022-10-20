// #include <iostream>

// using namespace std;

// int max_gcd = 0;

// int gcd(int x, int y) {
//     return y ? gcd(y, x % y) : x;
// }

// void check(int x, int y, int k) {
//     if (k == 0) {
//         max_gcd = max(max_gcd, gcd(x, y));
//         return ;
//     }
//     //对x操作
//     x += 1;
//     k -= 1;
//     check(x, y, k);
//     k += 1;
//     x -= 1;
//     //对y操作
//     y += 1;
//     k -= 1;
//     check(x, y, k);
//     k += 1;
//     y -= 1;
// }

// int main() {
//     int T;
//     cin >> T;
//     for (int i = 0; i < T; ++i) {
//         int x, y, k;
//         cin >> x >> y >> k;
//         max_gcd = 0;
//         check(x, y, k);
//         cout << max_gcd << endl;
        
//     }
    
//     return 0;
// }

// #include <iostream>

// using namespace std;

// int max_gcd = 0;

// int gcd(int x, int y) {
//  if (x < y) return gcd(y, x);
//  return y ? gcd(y, x % y) : x;
// }

// int check(int x, int y, int k) {
//  int max_gcd = 1;
//  for (int i = 0; i <= k; i++) {
//   max_gcd = max(max_gcd, gcd(x + i, y + k - i));
//  }
//  return max_gcd;
// }

// int main() {
//  int T;
//  cin >> T;
//  for (int i = 0; i < T; ++i) {
//   int x, y, k;
//   cin >> x >> y >> k;
//   cout << check(x, y, k) << endl;
//  }

//  return 0;
// }


// #include <iostream>
// #include <vector>
// #include <math.h>

// using namespace std;

// void check(vector<float>& nums, vector<vector<float>>& matrix1, vector<vector<float>>& matrix2, int t) {
//     int m = matrix1.size(); //行
//     int n = matrix1[0].size(); //列
//     vector<float> temp1(m);
//     vector<float> temp2(m);
//     for (int i = 0; i < m; ++i) {
//         for (int j = 0; j < n; ++j) {
//             temp1[i] += nums[j] * matrix1[i][j];
//             temp2[i] += nums[j] * matrix2[i][j];
//         }
//     }
//     for (int i = 0; i < m; ++i) {
//         temp1[i] = temp1[i] - temp2[i];
//     }
//     float r = 0.0;
//     for (int i = 0; i < m; ++i) {
//         r += temp1[i] * temp1[i];
//     }
//     if (sqrt(r) > t) cout << 1 << endl;
//     else cout << 0 << endl;
// }

// int main() {
//     int T;
//     cin >> T;
//     for (int k = 0; k < T; ++k) {
//         int n, m;
//         float t;
//         cin >> n >> m;
//         cin >> t;
//         vector<float> nums(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> nums[i];
//         }
//         vector<vector<float>> matrix1 = vector<vector<float>>(m, vector<float>(n, 0.0));
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 cin >> matrix1[i][j];
//             }
//         }
//         vector<vector<float>> matrix2 = vector<vector<float>>(m, vector<float>(n, 0.0));
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 cin >> matrix2[i][j];
//             }
//         }
//         check(nums, matrix1, matrix2, t);
//     }
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//  int n;
//  cin >> n;

//  vector<pair<int, int>> nums(n);
//  int x, y;
//  for (int i = 0; i < n; i++) {
//   cin >> x >> y;
//   nums[i] = { x, y };
//  }

//  sort(nums.begin(), nums.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
//   return p1.first < p2.first;
//  });

//  int x_range = nums[n / 2].first - nums[(n - 1) / 2].first;
//  if (x_range < 2) {
//   cout << -1 << endl;
//   return 0;
//  }
//  x = nums[(n - 1) / 2].first + 1;

//  sort(nums.begin(), nums.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
//   return p1.second < p2.second;
//  });
//  int y_range = nums[n / 2].second - nums[(n - 1) / 2].second;
//  if (y_range < 2) {
//   cout << -1 << endl;
//   return 0;
//  }
//  y = nums[(n - 1) / 2].second + 1;

//  cout << y << " " << x << endl;
//  return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n;
//      cin >> n;

//      vector<int> nums_x(n);
//      vector<pair<int, int>> nums_v(n);
//      int x, v;
//      for (int i = 0; i < n; i++) {
//       cin >> x >> v;
//       nums_x[i] = x;
//       nums_v[i] = { v, i };
//      }

//      sort(nums_x.begin(), nums_x.begin(), [](const int a, const int b)->bool {
//       return a < b;
//      });

//      sort(nums_v.begin(), nums_v.begin(), [](const pair<int, int>& p1, const pair<int, int>& p2)->bool {
//       return p1.first < p2.first;
//      });

//      vector<pair<pair<int, int>, int>> res(n);
//      for (int i = 0; i < n; i++)
//       res[i] = { { nums_x[i], nums_v[i].first }, nums_v[i].second };
//      sort(res.begin(), res.begin(), [](const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2)->bool {
//       return p1.second < p2.second;
//      });

//      for (int i = 0; i < n; i++) {
//       cout << res[i].first.first << " " << res[i].first.second << endl;
//      }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct node{
    int b;
    int c;
};

int min_num = 0x3f3f3f3f;
int start = 0;
int en = 0;

void check(unordered_map<int, vector<node>>& unmap, vector<bool>& used, int s, int dis) {
    if (s == en) {
        min_num = min(min_num, dis);
        return ;
    }
    
    for (int i = 0; i < unmap[s].size(); ++i) {
        if (used[unmap[s][i].b]) continue;
        dis += unmap[s][i].c;
        used[unmap[s][i].b] = true;
        check(unmap, used, unmap[s][i].b, dis);
        used[unmap[s][i].b] = false;
        dis -= unmap[s][i].c;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    //构建邻接表
    unordered_map<int, vector<node>> unmap;
    for (int i = 0; i < (n - 1); ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        unmap[a].push_back({b, c});
        unmap[b].push_back({a, c});
    }
    
    //依次遍历s和t节点
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            vector<bool> used(n + 1, false);
            used[i] = true;
            start = 5;
            en = 6;
            check(unmap, used, start, 0);
            res = max(res, min_num + nums[i] + nums[j]);
            min_num = 0x3f3f3f3f;
        }
    }
    cout << res << endl;
    return 0;
}