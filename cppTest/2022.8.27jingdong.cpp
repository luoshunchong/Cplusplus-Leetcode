/*
第一题：构造一个$n$行$n$列的矩阵，矩阵中的元素为$1$到$n^2$,每个数只出现一次，其中每两个相邻的数之和为奇数。
*/
// #include <iostream>
// #include <vector>

// using namespace std;

// void check(int n) {
//     int cur = 1;
//     for (int i = 0; i < n; ++i) {
//         if (i % 2 == 0) {
//             for (int j = 0; j < n; ++j) {
//                 cout << cur++;
//                 if (j < n) cout << " ";
//             }
//             cout << endl;
//         }
//         else {
//             cur += n - 1;
//             int temp = cur;
//             for (int j = 0; j < n; ++j) {
//                 cout << temp--;
//                 if (j < n) cout << " ";
//             }
//             cout << endl;
//             cur++;
//         }
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     check(n);
//     return 0;
// }

/*
第二题：将一个数组变为长城的最小操作次数，每次操作可以修改任意一个元素。（长城即奇数位数字全部相等、偶数位数字全部相等的数组，如[1,4,1,4,1,4,1]）
*/
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <map>

// using namespace std;

// void check(vector<int>& nums) {
//     unordered_map<int, int> odd;
//     unordered_map<int, int> even;
//     //统计一下奇数位，偶数位的数字出现的次数
//     for (int i = 0; i < nums.size(); ++i) {
//         if (i & 1) odd[nums[i]]++;
//         else even[nums[i]]++;
//     }
//     //交换位置，排序
//     multimap<int, int, greater<int> > odd1; //<次数， 数字>
//     multimap<int, int, greater<int> > even1;
//     for (auto o : odd) {
//         odd1.insert({o.second, o.first});
//     }
//     for (auto e : even) {
//         even1.insert({e.second, e.first});
//     }
//     multimap<int, int>::iterator iterodd = odd1.begin();
//     multimap<int, int>::iterator itereven = even1.begin();
//     if (iterodd->second != itereven->second) {
//         cout << (int)nums.size() - iterodd->first - itereven->first << endl;
//     }
//     else {
//         int a = iterodd->first, b = itereven->first;
//         iterodd++, itereven++;
//         if (a - iterodd->first > b - itereven->first) cout << nums.size() - a - itereven->first << endl;
//         else cout << nums.size() - b - iterodd->first << endl;
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }
//     check(nums);
//     return 0;
// }

/*
第三题：题目：给定任意一个长度为n的字符串，其中只要有两个"red"的子字符串就算是一种情况，求所有的情况总数。
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 6) {
        cout << 0;
        return 0;
    }
    if (n == 6) {  // 当n等于6时，只有一种情况
        cout << 1;
        return 0;
    }

    // 两个red的分布情况为sum(C(n-3-2)取1，一直累加到C1取1)
    int circle = 0;
    for (int i = n - 3 - 2; i > 0; i--) {
        circle += i;
    }
    // 剩下的字符串，每个都有26种可能
    // 这里注意要用次方，不是倍数
    int rate = 1;
    for (int i = 1; i <= n - 6; i++) {
        rate = (rate * 26)%(int(1e9+7)); 
    }
    cout << (circle * rate)%(int(1e9+7));
    return 0;
}
