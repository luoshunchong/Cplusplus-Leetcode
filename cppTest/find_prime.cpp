#include <iostream>
#include <vector>

using namespace std;

// vector<int> find_prime(int left, int right) {
//     vector<int> res;
//     vector<bool> p(right + 1, false);
//     for (int i = 2; i < right; ++i) {
//         if (!p[i]) {
//             if (i >= left) res.push_back(i);
//             for (int j = i + i; j < right; j += i) {
//                 p[j] = true;
//             }
//         }
//     }
//     return res;
// }

vector<int> find_prime(int left, int right) {
    vector<int> prime;
    vector<int> res;
    vector<bool> p(right, true);
    for (int i = 2; i < right; ++i) {
        if (p[i]) {
            prime.push_back(i);
            if (i >= left) res.push_back(i);
        }
        for (int j = 0; j < prime.size() && prime[j] * i < right; j++) {
            p[prime[j] * i] = false;
            if (i % prime[j] == 0) break;
        }
    }
    return res;
}

int main() {
    int left = 4, right = 10;
    vector<int> res = find_prime(left, right);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}
