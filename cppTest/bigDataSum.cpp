#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addString(string num1, string num2) {
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int temp = x + y + carry;
        res += '0' + temp % 10;
        carry = temp / 10;
        i--, j--;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string num1 = "82";
    string num2 = "34";
    string res = addString(num1, num2);
    cout << res << endl;
    return 0;
}