#include <iostream>
#include <string>
#include <unordered_map>;

using namespace std;

bool check(string s, int k) {
    unordered_map<int, int> ma;
    for (int i = 0; i < s.size(); ++i) {
        if (ma.find(s[i]) == ma.end()) {
            ma[s[i]] = 1;
        }
        else {
            ma[s[i]] ++;
        }
    }
    for (auto a : ma) {
        if (a.second > k) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 5, k = 1;
    // cin >> n >> k;
    string s;
    getline(cin, s);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string temp = s;
            temp.erase(i, j + 1);
            if (check(temp, k)) res++;
        }
    }
    cout << res << endl;
    return 0;
}