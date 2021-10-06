// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem547.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i]) //第i个节点没有访问过，从第i个节点开始访问
            {
                stack<int> visit;
                visit.push(i);
                while (!visit.empty())
                {
                    int temp = visit.top();
                    visit.pop();
                    visited[temp] = true;
                    for (int j = 0; j < isConnected.size(); ++j)
                    {
                        if (isConnected[temp][j] == 1 && !visited[j])
                        {
                            visit.push(j);
                        }
                    }
                }
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end
