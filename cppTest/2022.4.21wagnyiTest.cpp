#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int sum = 0;
    int res = 0;
    priority_queue<int> p;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        p.push(nums[i]);
    }
    int f = INT_MAX;
    while (!p.empty() && f != sum) {
        double mid = double(sum) / p.size();
        f = sum;
        while (p.top() > mid) {
            int temp = p.top();
            p.pop();
            sum -= temp;
        }
        res++;
    }
    
    cout << res << endl;
    return 0;
}


#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int, int> solution(int numerator, int denominator) {
    numerator %= denominator;
    if (numerator == 0) return {0, -1};
    int part = 0, part1 = 0, temp_denominator = 0, temp_denominator2 = 1;
    while ((denominator & 1) == 0) {
        denominator >>= 1;
        if ((denominator & 1) == 0) numerator >>= 1;
        else {
            if (denominator % 5) numerator *= 5;
            else denominator /= 5;
            temp_denominator++;
        }
    }
    while (denominator % 5 == 0) {
        if (numerator % 5 == 0) numerator /= 5;
        else {
            denominator /= 5;
            temp_denominator++;
            numerator <<= 1;
        }
    }
    if (denominator == 1) temp_denominator2 = 0;
    else {
        while (int(pow(10, temp_denominator2) - 1) % denominator != 0)
            temp_denominator2++;
    }
    if (temp_denominator2) {
        int temp = pow(10, temp_denominator2) - 1;
        numerator *= temp / denominator;
        if (temp_denominator) part = numerator / temp;
        part1 = numerator % temp;
    }
    int length_part = 0, length_part1 = 0;
    while (part1) {
        length_part1++;
        part1 /= 10;
    }
    if (!part) return {0, length_part1};
    
    while (part) {
        length_part++;
        part /= 10;
    }
    return {length_part, length_part1};
}

int main() {
    int p, q;
    cin >> p >> q;
    auto res = solution(p, q);
    if (!(res.first || res.second) || res.second == -1) {
        cout << -1 << endl;
    }
    else {
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}