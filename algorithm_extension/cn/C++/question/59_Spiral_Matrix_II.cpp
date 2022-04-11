// @algorithm @lc id=59 lang=cpp 
// @title spiral-matrix-ii


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(3)=[[1,2,3],[8,9,4],[7,6,5]]
// @test(1)=[[1]]
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int count = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (true) {
            for (int i = left; i <= right; ++i) {
                res[top][i] = count;
                count++;
            }
            if (++top > bottom) break;
            for (int i = top; i <= bottom; ++i) {
                res[i][right] = count;
                count++;
            }
            if (--right < left) break;
            for (int i = right; i >= left; --i) {
                res[bottom][i] = count;
                count++;
            }
            if (--bottom < top) break;
            for (int i = bottom; i >= top; --i) {
                res[i][left] = count;
                count++;
            }
            if (++left > right) break;
        }
        return res;
    }
};