// @algorithm @lc id=93 lang=cpp 
// @title restore-ip-addresses


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("25525511135")=["255.255.11.135","255.255.111.35"]
// @test("0000")=["0.0.0.0"]
// @test("101023")=["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// @test("255255255255")=["255.255.255.255"]
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        //判断边界条件
        if (s.size() < 4 || s.size() > 12) return {};
        string temp = s;
        backtracking(s, temp, 0, 1);
        return res;
    }
    void backtracking(string s, string temp, int pos, int t) {
        if (temp.size() == s.size() + 3) {
            if (check(temp)) res.push_back(temp);
            return ;
        }
        for (int i = pos; i < s.size(); ++i) {
            temp.insert(i + t, ".");
            t++;
            backtracking(s, temp, i + 1, t);
            t--;
            temp.erase(i + t, 1);
            
        }
    }
    bool check(string s) {
        int start = 0;
        int i = 0;
        for (; i < s.size(); ++i) {
            if (s[i] == '.') {
                string t = s.substr(start, i - start);
                if (t.size() > 1 && t[0] == '0') return false;
                if (t.size() > 3) return false;
                int num = stoi(t);
                if (num > 255 || num < 0) return false;  
                start = i + 1;
            }
        }
        if (i == start) return false;
        string t = s.substr(start, i - start);
        if (t.size() > 1 && t[0] == '0') return false;
        if (t.size() > 3) return false;
        int num = stoi(t);
        if (num > 255 || num < 0) return false;  
        return true;
    }
};