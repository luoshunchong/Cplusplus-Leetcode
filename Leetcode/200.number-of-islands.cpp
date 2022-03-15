// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem200.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        vector<vector<int>> mark;
        //初始化mark
        for (int i = 0; i < grid.size(); ++i)
        {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); ++j)
            {
                mark[i].push_back(0);
            }
        }
        //开始遍历grid数组
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (mark[i][j] == 0 && grid[i][j] == '1')
                {
                    DFS(mark, grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<int>> &mark, vector<vector<char>> &grid, int x, int y)
    {
        mark[x][y] = 1; //标记已搜寻的位置
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i)
        {
            int new_x = dx[i] + x;
            int new_y = dy[i] + y;
            if (new_x < 0 || new_x > mark.size() || new_y < 0 || new_y > mark[new_x].size())
            {
                continue;
            }
            if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')
            {
                DFS(mark, grid, new_x, new_y);
            }
        }
    }
};
// @lc code=end
