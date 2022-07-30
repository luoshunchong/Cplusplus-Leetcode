// @algorithm @lc id=1234 lang=cpp 
// @title number-of-paths-with-max-score

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(["E23","2X2","12S"])=[7,1]
// @test(["E12","1X1","21S"])=[4,2]
// @test(["E11","XXX","11S"])=[0,0]
class Solution {
public:
    int maxSum = 0;
    int sumPath = 0;
    int mod = 1000000007;
    vector<int> X = {-1, 1, 0, 0};
    vector<int> Y = {0, 0, -1, 1};
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<char>> temp;
        for (auto b : board) {
            vector<char> t;
            for (auto u : b) {
                t.push_back(u);
            }
            temp.push_back(t);
        }
        dfs(temp, 0, 0, 0);
        return {maxSum, sumPath};
    }
    void dfs(vector<vector<char>>& board, int x, int y, int sum) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 'X') return ;
        if (board[x][y] == 'S') {
            if (sum == maxSum) sumPath++;
            else if(sum > maxSum) {
                maxSum = sum;
                sumPath = 1;
            }
            else return ;
        }
        sum += board[x][y] - '0';
        for (int i = 0; i < 4; ++i) {
            int newx = x + X[i];
            int newy = y + Y[i];
            dfs(board, newx, newy, sum);
        }
    }
};