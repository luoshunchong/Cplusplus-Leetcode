#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main() {
    map<int, int> ma;
    ma[2] = 4;
    ma[3] = 5;
    ma[4] = 6;
    auto itupper = ma.upper_bound(3);
    cout << itupper->first << " " << itupper->second << endl;
    auto itlower = ma.lower_bound(3);
    cout << itlower->first << " " << itlower->second << endl;

    vector<pair<int, int>> temp;
    temp.push_back({2,3});
    temp.push_back({5,6});
    sort(temp.begin(), temp.end(), cmp);
    auto it = lower_bound(temp.begin(), temp.end(), make_pair(2, 0));
    cout << it->first << " " << it->second << endl;
    return 0;
}