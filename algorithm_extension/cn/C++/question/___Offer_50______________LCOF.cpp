// @algorithm @lc id=100316 lang=cpp 
// @title di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof


#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include "algm/algm.h"
using namespace std;
// @test("abaccdeff")='b'
// @test("")=''
class Solution {
public:

struct cmp {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second <= b.second;
    }
};

    char firstUniqChar(string s) {
        set<pair<char, int>, cmp> ma;
        for (int i = 0 ; i < s.size(); ++i) {
            ma.insert(pair<char, int>(s[i], i));
        }
        return ma.begin()->first;
    }
};