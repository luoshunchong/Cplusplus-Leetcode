#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int res = 0;
string temp = "";
void check(string s) {
    int val = 0;
    int preval = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0) {
            preval = 1;
            val = 1;
        }
        else {
            if (s[i] == s[i - 1]) {
                val += (preval + 1);
                preval += 1;
            }
            else {
                val += 1;
                preval = 1;
            }
        }
    }
    if (val > res) res = val;
}
void dfs(string s, int n, int pos) {
    if (pos == n) {
        unse.insert(temp);
        cout << temp << endl;
        check(temp);
        return ;
    }
    if (unse.count(temp) != 0) return ;
    //选或不选
    for (int i = pos; i < n; ++i) {
        temp.push_back(s[i]);
        dfs(s, n, i + 1);
        temp.pop_back();
    }
}

int main() {
    // int n;
    // cin >> n;
    // string s;
    // cin >> s;

    int n = 4;
    string s = "1100";
    dfs(s, n, 0);
    cout << res << endl;
    return 0;
}