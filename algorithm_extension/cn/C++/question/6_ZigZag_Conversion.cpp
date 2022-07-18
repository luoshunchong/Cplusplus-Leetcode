// @algorithm @lc id=6 lang=cpp 
// @title zigzag-conversion

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("PAYPALISHIRING",3)="PAHNAPLSIIGYIR"
// @test("PAYPALISHIRING",4)="PINALSIGYAHRPI"
// @test("A",1)="A"
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> arr(numRows);
        bool flag = false;
        int curRow = 0;
        for (auto t : s) {
            arr[curRow] += t;
            if (curRow == 0 || curRow == numRows - 1) flag = !flag;
            curRow += flag ? 1 : -1;
        }
        string res = "";
        for (auto a : arr) {
            res += a;
        }
        return res;
    }
};