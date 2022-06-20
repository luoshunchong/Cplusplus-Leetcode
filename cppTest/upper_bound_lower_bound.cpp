#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> ma;
    ma[2] = 4;
    ma[3] = 5;
    ma[4] = 6;
    auto itupper = ma.upper_bound(3);
    cout << itupper->first << " " << itupper->second << endl;
    auto itlower = ma.lower_bound(3);
    cout << itlower->first << " " << itlower->second << endl;
    return 0;
}