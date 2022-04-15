// @algorithm @lc id=100328 lang=cpp 
// @title fan-zhuan-dan-ci-shun-xu-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("the sky is blue")="blue is sky the"
// @test("  hello world!  ")="world! hello"
// @test(" ")=""
class Solution {
public:
    string reverseWords(string s) {
        
    }
    string reverse(string &s, int left, int right) {
        while (left < right) {
            s[left] = s[right] ^ s[left];
            s[right] = s[right] ^ s[left];
            s[left] = s[right] ^ s[left];
            left++;
            right--;
        }
        return s;
    }
};