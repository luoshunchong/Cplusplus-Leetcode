// @algorithm @lc id=100280 lang=cpp 
// @title ti-huan-kong-ge-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("We are happy.")="We%20are%20happy."
class Solution {
public:
    string replaceSpace(string s) {
        int len1 = 0;
        //遍历一遍，统计有多少个空格
        for (auto a : s) {
            if (a == ' ') len1++;
        }
        //计算字符串的总长度
        int lensum = s.size() + (len1 * 2);
        //resize一下原字符串
        int left = s.size() - 1;
        s.resize(lensum);
        int right = s.size() - 1;
        //从后面开始遍历找到空格就进行替换
        while (left >= 0 && right >= 0) {
            if (s[left] == ' ') {
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
            }
            else {
                s[right--] = s[left];
            }
            left--;
        }
        return s;
    }
};