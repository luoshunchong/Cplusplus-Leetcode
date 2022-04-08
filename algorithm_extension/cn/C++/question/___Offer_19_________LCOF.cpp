// @algorithm @lc id=100297 lang=cpp 
// @title zheng-ze-biao-da-shi-pi-pei-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("mississippi","mis*is*p*.")=false
// @test("ab",".*")=true
// @test("aab","c*a*b")=true
// @test("aab","c*a*ab")=true
// @test("aab","c*a*aaab")=false
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0) return true;
        if (s.size() == 0 || p.size() == 0) return false;
        int s1 = 0, p1 = 0;
        while (s1 < s.size() && p1 < p.size()) {
            if (p1 == p.size() - 1 || p[p1 + 1] != '*') {
                if (s[s1] == p[p1] || p[p1] == '.') {
                    s1++;
                    p1++;
                }
                else {
                    return false;
                }
            }
            else {
                if (s[s1] != p[p1] && p[p1] != '.') {
                    p1 += 2;
                }
                else {
                    if (p[p1 + 2] != p[p1]) {
                        while (s[s1] == s[s1 + 1]) s1++;
                        p1 += 2;
                    }
                    else {
                        p1 += 2;
                        int countp = 0;
                        while (p[p1] == p[p1 + 1]) {
                            p1++;
                            countp++;
                        }
                        int counts = 0;
                        while (s[s1] == s[s1 + 1]) {
                            s1++;
                            counts++;
                        }
                        if (counts > countp) return false;
                    }
                }
            }
        }
        if (s1 == s.size() - 1 && p1 == p.size() - 1) return true;
        return false;
    }
};