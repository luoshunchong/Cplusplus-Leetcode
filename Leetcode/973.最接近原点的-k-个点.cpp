// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
    int distance(vector<int> &a)
    {
        return a[0] * a[0] + a[1] * a[1];
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> sum;
        vector<int> index;
        int i = 0;
        for (auto &a : points)
        {
            sum.push_back(distance(a));
            index.push_back(i++);
        }
        sort(index.begin(), index.end(), [&](int x, int y) {
            return sum[x] < sum[y];
        });
        vector<vector<int>> ans;
        for (i = 0; i < K; i++)
        {
            ans.push_back(points[index[i]]);
        }
        return ans;
    }
};
// @lc code=end

