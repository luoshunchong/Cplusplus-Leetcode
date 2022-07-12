#include <iostream>
#include <vector>

using namespace std;

/*
情况一：使用cin输入，遇到空格、不符合格式的数据、异常值等都会停止。
有的时候就可以利用cin遇到异常终止的特点来输入。例如：情况三
*/
// int main() {
//     int a;
//     cin >> a;
//     cout << a << endl;
//     return 0;
// }

/*
情况二：每一行不知道有多少个数据  使用cin.get()判断是不是换行了
每一行不确定有多少个数字，用空格分开
1 2 3
4 5
0 0 0 0 0
*/
// int main() {
//     int a, sum = 0;
//     while (cin >> a) {
//         sum += a;
//         if (cin.get() == '\n') {
//             cout << sum << endl;
//             sum = 0;
//         }
//     }
//     return 0;
// }

/*
情况三：使用getline输入一整行
输入：3
     abc
*/
// int main() {
//     string a;
//     string b;
//     cin >> a;
//     getline(cin, b);

//     cout << a << endl;
//     cout << b << endl;

//     return 0;
// }

/*
情况四：输入[[1,2],[3,4],[5,6]]
*/
// int main() {
//     vector<pair<int, int>> nums;
//     char temp;
//     int h, w;
//     while (cin >> temp) {
//         if(temp == ']') break;
//         cin >> temp >> h >> temp >> w >> temp;
//         nums.push_back({h, w});
//     }
//     cout << 1 << endl;
// }

/*
输入用逗号隔开
a,f,g
*/
// int main() {
//     string s;
//     getline(cin, s);
//     vector<char> str;
//     for (auto i : s) {
//         if (i == ',') continue;
//         str.push_back(i);
//     }
//     cout << 1 << endl;
//     return 0;
// }

/*
输入带有负号
3 个数
-13
-2
4
*/
int main() {
    vector<int> nums;
    int n;
    cin >> n;
    int a;
    char b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (b >= '0' && b <= '9') {
            nums.push_back(b - '0');
            continue;
        }
        cin >> a;
        if (b == '-') a = -a;
        nums.push_back(a);
    }
    cout << 1 << endl;
    return 0;
}