// @algorithm @lc id=593 lang=cpp 
// @title valid-square

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include "algm/algm.h"
using namespace std;
// @test([0,0],[1,1],[1,0],[0,1])=true
// @test([0,0],[1,1],[1,0],[0,12])=false
// @test([1,0],[-1,0],[0,1],[0,-1])=true
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //计算机六条边的距离
        vector<int> temp(6);
        temp[0] = dis(p1, p2);
        temp[1] = dis(p1, p3);
        temp[2] = dis(p1, p4);
        temp[3] = dis(p2, p3);
        temp[4] = dis(p2, p4);
        temp[5] = dis(p3, p4);
        //求出任意两点之间的六条边后，从小到大排序。
        //如果前四条边相等，后两条边相等，且后两条边的长度大于前四条边边，则可以组成正方形。
        sort(temp.begin(), temp.end());
        if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3] && temp[4] == temp[5]) return true;
        else return false;
    }
    int dis(vector<int>& p, vector<int>& q) {
        return pow((p[0] - q[0]), 2) + pow((p[1] - q[1]), 2);
    }
};