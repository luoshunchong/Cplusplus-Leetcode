// @algorithm @lc id=753 lang=cpp 
// @title open-the-lock

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "algm/algm.h"
using namespace std;
// @test(["0201","0101","0102","1212","2002"],"0202")=6
// @test(["8888"],"0009")=1
// @test(["8887","8889","8878","8898","8788","8988","7888","9888"],"8888")=-1
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int res = 0;

        unordered_set<string> unse;
        for (auto d : deadends) unse.insert(d);
        if (unse.count("0000")) return -1; //判断起点

        unordered_set<string> visited;

        unordered_set<string> q1;
        unordered_set<string> q2;
        q1.insert("0000");
        q2.insert(target);
        // 将 q1 中的所有节点向周围扩散
        while (!q1.empty() && !q2.empty()) {
            unordered_set<string> temp;
            for (auto q : q1) {
                //判断出口
                if (unse.count(q)) continue;
                visited.insert(q);
                if (q2.count(q)) return res;
                for (int i = 0; i < 4; ++i) {
                    string temp1 = updo(q, i);
                    if (visited.count(temp1) == 0) {
                        temp.insert(temp1);
                    }
                    string temp2 = downdo(q, i);
                    if (visited.count(temp2) == 0) {
                        temp.insert(temp2);
                    }
                }
            }
            res++;
            q1 = q2;
            q2 = temp;
        }
        return -1;
    }
    string updo(string s, int pos) {
        if (s[pos] == '9') s[pos] = '0';
        else s[pos] = (s[pos] - '0' + 1) + '0';
        return s;
    }
    string downdo(string s, int pos) {
        if (s[pos] == '0') s[pos] = '9';
        else s[pos] = (s[pos] - '0' - 1) + '0';
        return s;
    }
};