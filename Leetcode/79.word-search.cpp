// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem79.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool flag = false;
    vector<int> X = {-1, 1, 0, 0};
    vector<int> Y = {0, 0, -1, 1};
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> used(board.size(), vector<bool>(board[0].size()));
                    used[i][j] = true;
                    dfs(board, word, used, i, j, 1);
                    // cout << flag << endl;
                    if (flag) return true;
                }
            }
        }
        return false;
    }
    void dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& used, int x, int y, int pos) {
        
        if (pos == word.size()) {
            flag = true;
            return ;
        }
        
        for (int i = 0; i < 4; ++i) {
            int new_x = x + X[i];
            int new_y = y + Y[i];
            if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size() && used[new_x][new_y] == false && board[new_x][new_y] == word[pos]) {
                used[new_x][new_y] = true;
                dfs(board, word, used, new_x, new_y, pos + 1);
                used[new_x][new_y] = false;
            } 
        }
    }
};
// @lc code=end
