#include <iostream>
#include <vector>

using namespace std;

void check(vector<vector<char>>& a, int x, int y) {
    if (x < 0 || x >= a.size() || y < 0 || y >= a[0].size() || a[x][y] == '.') return ;
    a[x][y] = '.';
    //上
    check(a, x - 2, y);
    //下
    check(a, x + 2, y);
    //左
    check(a, x, y - 2);
    //右
    check(a, x, y + 2);
}

int main() {
    int n = 3, m = 4;
    // cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        string temp = "";
        getline(cin, temp);
        for (int j = 0; j < m; ++j) {
            a[i][j] = temp[j];
        }
        temp = "";
    }
    
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '*') {
                res++;
                
                check(a, i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}