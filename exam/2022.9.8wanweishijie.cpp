
/*
在一个矩阵grid中，0表示通过，1表示障碍。求从（0, 0）点走到（grid.size() - 1, grid[0].size() - 1）
位置路径长度等于grid.size() - 1 + grid[0].size() - 1 - 2的路径数。
*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int res = 0;
    vector<int> X = {-1, 1, 0, 0};
    vector<int> Y = {0, 0, -1, 1};
    int solution(vector<vector<int> >& grid) {
        // write code here
        if (grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1) return 0;
        dfs(grid, 0, 0, 0);
        return res;
    }
    void dfs(vector<vector<int> >& grid, int x, int y, int num) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 1) return ;
        
        if (x == grid.size() - 1 && y == grid[0].size() - 1 && num == (grid.size() + grid[0].size() - 2)) {
            res++;
            return ;
        }
        num++;
        grid[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int new_x = x + X[i];
            int new_y = y + Y[i];
            dfs(grid, new_x, new_y, num);
        }
        grid[x][y] = 0;
    }
};

int main() {
    vector<vector<int>> grid = {{0,0, 1}, {0, 0, 0}, {0,0,0}};
    Solution a;
    a.solution(grid);
    cout << a.res << endl;
}