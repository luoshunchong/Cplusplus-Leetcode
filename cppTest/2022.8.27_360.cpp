/*
第二题：需要在已有的路网上规划一些路段进行翻新，保证规划中的翻新道路经过了所有路网上的结点。同时所有翻新的路段必须构成一颗树，
即不存在一段不与其他翻新路段相连的新路段，计算翻新路段最小长度和。
输入：
第一行有两个数n,m，分别表示节点数和路段数
接下来三行，每一行有m个正整数，每行分别对应{start,end,len}；

输出：
输出一行，表示一个整数，最小长度和

输入：
3 3
1 1 2
2 3 3
885 513 817
输出：
1330

*/
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct node{
//     int start;
//     int end;
//     int length;
// };
// bool cmp(node a, node b) {
//     return a.length < b.length;
// }

// int father[99999];
// int findFather(int x) {
//     int a = x;
//     while (x != father[x]) {
//         x = father[x];
//     }
//     while (a != father[a]) {
//         int z = a;
//         a = father[a];
//         father[z] = x;
//     }
//     return x;
// }

// void check(vector<node>& edge) {
//     int N = edge.size();
//     for (int i = 0; i < N; ++i) {
//         father[i] = i;
//     }
//     sort(edge.begin(), edge.end(), cmp);
//     long long weight = 0;
//     for (int i = 0; i < N; ++i) {
//         int faU = findFather(edge[i].start);
//         int faV = findFather(edge[i].end);
//         if (faU != faV) {
//             father[faU] = faV;
//             weight += edge[i].length;
//         }
//     }
//     cout << weight << endl;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<node> nums(m, {0, 0, 0});
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < m; ++j) {
//             if (i == 0) {
//                 cin >> nums[j].start;
//             }
//             if (i == 1) {
//                 cin >> nums[j].end;
//             }
//             if (i == 2) {
//                 cin >> nums[j].length;
//             }
//         }
//     }
//     check(nums);
//     return 0;
// }

/*
第一题：平时成绩占比p,期末考试成绩占比q;平时分a，期末考试成绩b，则总成绩为(p*a + q*b)/100.老师坚持期末考试成绩高的平时成绩也更高。
在这种情况下，最大及格人数是多少(成绩不低于60)?
输入：
第一行三个正整数n,p,q;
第二行n个正整数表示n个学生的期末考试成绩
输出：
最大及格人数

输入：
2 50 50
50 50

输出：
2
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void check(vector<int>& nums, int p, int q) {
    sort(nums.begin(), nums.end());
    vector<int> rank(nums.size(), 0);
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) rank[i] = rank[i + 1] + 1;
        else rank[i] = rank[i + 1];
    }
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        int cur_max_usual_performance = 100 - rank[mid];
        double final_score = p / 100.0 * cur_max_usual_performance + q / 100.0 * nums[mid];
        if (final_score >= 60) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << nums.size() - left << endl;
}

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    check(nums, p, q);
    return 0;
}