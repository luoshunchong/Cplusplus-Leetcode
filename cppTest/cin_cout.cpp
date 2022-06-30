#include <iostream>
#include <vector>

using namespace std;

// int main() {
//     string a;
//     string b;
//     cin >> a;
//     getline(cin, b);

//     cout << a << endl;
//     cout << b << endl;

//     system("pause");
//     return 0;
// }

// [[1,2],[3,4],[5,6]]
int main() {
    vector<pair<int, int>> nums;
    char temp;
    int h, w;
    while (cin >> temp) {
        if(temp == ']') break;
        cin >> temp >> h >> temp >> w >> temp;
        nums.push_back({h, w});
    }
    cout << 1 << endl;
}