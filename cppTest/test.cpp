#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<int> nums;
    int sum = 0;
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            nums.push_back(stoi(temp));
            sum += stoi(temp);
            temp = "";
        }
        temp.push_back(s[i]);
    }
    nums.push_back(stoi(temp));
    sum += stoi(temp);
    sum /= (int)nums.size();

    int t = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        t = nums[i] + t - sum;
        if (t != 0) res++;
    }
    cout << res << endl;
    return 0;
}
