// @before-stub-for-debug-begin
#include <vector>
#include <stack>
#include <string>
#include "commoncppproblem695.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>> &grid) //第一种递归的写法
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j])
                {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        if (grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int k = 0; k < 4; ++k)
        {
            x = r + direction[k], y = c + direction[k + 1];
            if (x < grid.size() && x >= 0 && y >= 0 && y < grid[0].size())
            {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};
// @lc code=end
