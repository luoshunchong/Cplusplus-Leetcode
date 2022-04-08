// @algorithm @lc id=100296 lang=cpp 
// @title da-yin-cong-1dao-zui-da-de-nwei-shu-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(1)=[1,2,3,4,5,6,7,8,9]
class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if (n == 0) return {0};
        string s(n, '0');
        bool flag = true;
        while (flag) {
            //字符串相加
            int carry = 0; //表示进位
            for (int i = n - 1; i >= 0; --i) {
                int temp = s[i] - '0' + carry;
                if (i == (n - 1)) temp++; //加一操作
                if (temp >= 10) { //判断是否需要进位
                    if (i == 0) flag = false; 
                    else {
                        carry = 1;
                        s[i] = temp - 10 + '0';
                    }
                }
                else {
                    s[i] = temp + '0';
                    break;
                }
            }
            //打印数字
            if (flag) {
                string str_num = "";
                bool is_Start = false;
                for (int i = 0; i < n; ++i) {
                    if (s[i] != '0') is_Start = true;
                    if (is_Start) {
                        str_num += s[i];
                    }
                }
                res.push_back(stoi(str_num));
            }
        }
        return res;
    }
};