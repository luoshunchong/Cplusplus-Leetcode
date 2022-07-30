// @algorithm @lc id=592 lang=cpp 
// @title fraction-addition-and-subtraction

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("-1/2+1/2")="0/1"
// @test("-1/2+1/2+1/3")="1/3"
// @test("1/3-1/2")="-1/6"
// @test("7/2+2/3-3/4")="41/12"
// @test("-5/2+10/3+7/9")="29/18"
class Solution {
public:
    string fractionAddition(string expression) {
        if (isdigit(expression[0])) {
            expression.insert(0, "+");
        }
        int a; //分子
        int b; //分母
        char c; //符号
        vector<string> temp = {"+", "0", "/", "1"};
        for (int i = 0; i < expression.size(); ++i) {
            if ((i + 1) % 4 == 0) {
                a = expression[i - 2] - '0';
                b = expression[i] - '0';
                c = expression[i - 3];
                int ta = stoi(temp[1]);
                int tb = stoi(temp[3]);
                string tc = temp[0];
                int newb = lcm(tb, b);
                int newa;
                if (tc == "-" && c == '-') {
                    newa = -(newb / b * a + newb / tb * ta);
                    temp[0] = "-";
                }
                else if (tc == "-" || c == '-'){
                    if (tc == "-") {
                        newa = newb / b * a - newb / tb * ta;
                    }
                    else {
                        newa = - newb / b * a + newb / tb * ta;
                    }
                    if (newa >= 0) temp[0] = "+";
                    else temp[0] = "-";
                }
                else {
                    newa = newb / b * a + newb / tb * ta;
                    temp[0] = "+";
                }
                temp[1] = to_string(abs(newa));
                temp[3] = to_string(newb);
            }
        }
        //处理temp
        // for (auto t : temp) cout << t << " ";
        // cout << endl;
        if (temp[1] == "0") temp[3] = "1";
        else {
            int t1 = stoi(temp[1]), t2 = stoi(temp[3]);
            int t = gcd(t1, t2);
            temp[1] = to_string(t1 / t);
            temp[3] = to_string(t2 / t);
        }
        string res = "";
        for (auto t : temp) {
            res += t;
        }
        if (res[0] == '+') res = res.substr(1);
        
        return res;
    }
    int lcm(int a, int b) {
        int num1 = a, num2 = b;
        while (a % b) {
            int r = a % b;
            a = b;
            b = r;
        }
        return (num1 * num2) / b;
    }
    int gcd(int a, int b) {
        while (a % b) {
            int r = a % b;
            a = b;
            b = r;
        }
        return b;
    }
};