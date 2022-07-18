// @algorithm @lc id=750 lang=cpp 
// @title contain-virus

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]])=10
// @test([[1,1,1],[1,0,1],[1,1,1]])=4
// @test([[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]])=13
class Solution {
public:
    vector<vector<int>> used;
    int res = 0;
    vector<int> X = {-1, 1, 0, 0};
    vector<int> Y = {0, 0, -1, 1};
    int containVirus(vector<vector<int>>& isInfected) {
        used = vector<vector<int>>(isInfected.size(), vector<int>(isInfected[0].size(), 0));
        //标记已存在病毒的地方
        for (int i = 0; i < isInfected.size(); ++i) {
            for (int j = 0; j < isInfected[0].size(); ++j) {
                if (isInfected[i][j]) used[i][j] = 1;
            }
        }
        //for循环找感染的区域
        for (int i = 0; i < isInfected.size(); ++i) {
            for (int j = 0; j < isInfected[0].size(); ++j) {
                if (isInfected[i][j]) {
                    //遍历被感染的区域，并隔离
                    dfs(isInfected, i, j);
                    //记录被扩散的区域
                    check(isInfected);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& isInfected, int i, int j) {
        if (i < 0 || i >= isInfected.size() || j < 0 || j >= isInfected[0].size()) return ;
        if (isInfected[i][j] == 0) {
            res++;
            return ;
        }
        if (isInfected[i][j] == 2) return ;
        for (int k = 0; k < 4; ++k) {
            int newx = i + X[k];
            int newy = j + Y[k];
            dfs(isInfected, newx, newy);
        }
    }
    void check(vector<vector<int>>& isInfected) {
        for (int i = 0; i < isInfected.size(); ++i) {
            for (int j = 0; j < isInfected[0].size(); ++j) {
                if (isInfected[i][j] == 1 && used[i][j] == 1) {
                    //向左扩散
                    if (j > 0 && used[i][j - 1] == 0) used[i][j - 1] = 1;
                    //向右扩散
                    if (j < isInfected[0].size() - 1 && used[i][j + 1] == 0) used[i][j + 1] = 1;
                    //向上扩散
                    if (i > 0 && used[i - 1][j] == 0) used[i - 1][j] = 1;
                    //向下扩散
                    if (i < isInfected.size() - 1 && used[i + 1][j] == 0) used[i + 1][j] = 1;
                }
            }
        }
        for (int i = 0; i < isInfected.size(); ++i) {
            for (int j = 0; j < isInfected[0].size(); ++j) {
                if (used[i][j] == 1 && isInfected[i][j] == 0) isInfected[i][j] = 1;
            }
        }
    }
};