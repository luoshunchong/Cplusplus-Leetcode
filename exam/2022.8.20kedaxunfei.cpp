#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
float P = 3.1415927;
float hanwin(int num, int N) {
    float res = 0.5 * (1 - cos(2 * P * num / N));
    return res;
}

void check(vector<int>& nums, int N) {
    for (int i = 0; i < nums.size(); ++i) {
        float res = (float)nums[i] * hanwin(i, N);
        if (res < 0) cout << int(res - 0.5) << " ";
        else cout << int(res + 0.5) << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums;
    string s;
    cin.ignore();
    getline(cin, s);
    string temp;
    bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            int t = stoi(temp);
            if (flag) t = -t;
            nums.push_back(t);
            temp = "";
            flag = false;
        }
        else if (s[i] == '-') flag = true;
        else temp.push_back(s[i]);
    }
    int t = stoi(temp);
    if (flag) t = -t;
    nums.push_back(t);
    check(nums, N);
    return 0;
}