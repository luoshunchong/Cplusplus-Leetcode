/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
    vector<int> X = {-1, 1, 0, 0};
    vector<int> Y = {0, 0, -1, 1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int res = 0;
        vector<vector<bool>> used(maze.size(), vector<bool>(maze[0].size(), false));
        queue<int> qu;
        qu.push(entrance[0]);
        qu.push(entrance[1]);
        int flag = false;
        while (!qu.empty()) {
            int level = qu.size() / 2;
            for (int k = 0; k < level; ++k) {
                int x = qu.front();
                qu.pop();
                int y = qu.front();
                qu.pop();
                used[x][y] = true;
                //判断逻辑
                //如果是边缘，已经找到
                if (x <= 0 || x >= maze.size() - 1 || y <= 0 || y >= maze[0].size() - 1) {
                    if (res != 0) {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 4; ++i) {
                    int new_x = x + X[i];
                    int new_y = y + Y[i];
                    if (new_x >= 0 && new_x <= maze.size() - 1 && new_y >= 0 && new_y <= maze[0].size() - 1) {
                        if (maze[new_x][new_y] == '.' && !used[new_x][new_y]) {
                            qu.push(new_x);
                            qu.push(new_y);
                        }
                    }
                }
            }
            if (flag) break;
            res++;
        }
        if (flag) return res;
        return -1;
    }
};
// @lc code=end

