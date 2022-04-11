// @algorithm @lc id=100293 lang=cpp 
// @title shun-shi-zhen-da-yin-ju-zhen-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([[1,2,3],[4,5,6],[7,8,9]])=[1,2,3,6,9,8,7,4,5]
// @test([[1,2,3,4],[5,6,7,8],[9,10,11,12]])=[1,2,3,4,8,12,11,10,9,5,6,7]
// @test([[6,9,7]])=[6,9,7]
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size(); //rows行，columns列
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (true) {
            //从左到右
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            if (++top > bottom) break;
            //从上到下
            for (int row = top; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (--right < left) break;
            //从右到左
            for (int column = right; column >= left; column--) {
                order.push_back(matrix[bottom][column]);
            }
            if (--bottom < top) break;
            //从下到上
            for (int row = bottom; row >= top; row--) {
                order.push_back(matrix[row][left]);
            }
            if (++left > right) break;
        }
        return order;
    }
};