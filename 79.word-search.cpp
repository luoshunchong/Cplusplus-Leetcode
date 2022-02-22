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
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                backtracking(i, j, board, word, find, visited, 0);
            }
        }
        return find;
    }
    void backtracking(int i, int j, vector<vector<char>> &board, string word, bool &find, vector<vector<bool>> &visited, int pos)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (find || visited[i][j] || board[i][j] != word[pos])
            return;
        if (pos == word.size() - 1)
        {
            find = true;
            return;
        }
        visited[i][j] = true;
        backtracking(i + 1, j, board, word, find, visited, pos + 1);
        backtracking(i - 1, j, board, word, find, visited, pos + 1);
        backtracking(i, j + 1, board, word, find, visited, pos + 1);
        backtracking(i, j - 1, board, word, find, visited, pos + 1);
        visited[i][j] = false;
    }
};
// @lc code=end
