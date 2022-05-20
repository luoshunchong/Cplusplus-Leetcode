#include <iostream>
#include <algorithm>
using namespace std;

string sub(string a, string b) {
    string res = "";
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0) {
        int x = i >= 0 ? a[i] - '0' : 0;
        int y = j >= 0 ? b[j] - '0' : 0;
        int temp = (x - borrow - y + 10) % 10;
        res += temp + '0';
        borrow = x - borrow - y < 0 ? 1 : 0;
        i--, j--;
    }
    reverse(res.begin(), res.end());
    //删除前导0。循环条件是res.size()-1是为防止"0000"的情况
    int pos;
    for (pos = 0; pos < res.size() - 1; pos++) {
        if (res[pos] != '0') break;
    }
    return res.substr(pos);
}
/*
如何比较两个大数的大小呢？
由于是大数，肯定不能直接转成int比较。
我们可以比较两个字符串的长度。
长度更长的字符串，数一定更大；当长度一样的就去比较字典序。
*/
bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

/*
两个非负整数相减的结果可能为负。
因此，首先比较两个数的大小。
如代码所示，当小减大时，需将两个参数调换一下位置执行减法，在结果前填上负号即可
*/
string subStrings(string num1, string num2) {
    string res;
    if (cmp(num1, num2)) {
        res = sub(num2, num1);
        if (res != "0") res.insert(0, "-");
    }
    else res = sub(num1, num2);
    return res;
}


int main() {
    string a = "23";
    string b = "12";
    cout << subStrings(a, b) << endl;
    return 0;
}