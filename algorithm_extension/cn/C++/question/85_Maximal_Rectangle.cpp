// @algorithm @lc id=85 lang=cpp 
// @title maximal-rectangle


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])=6
// @test([["0"]])=0
// @test([["1"]])=1
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int>> len_matrix(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0 ; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    len_matrix[i][j] = (j == 0 ? 1 : len_matrix[i][j - 1] + 1);
                }
            }
        }
        //对矩阵中的每一列按照单调栈的方式求解
        int res = 0;
        vector<int> zero(matrix[0].size(), 0);
        len_matrix.insert(len_matrix.begin(), zero);
        len_matrix.push_back(zero);
        for (int i = 0; i < matrix[0].size(); ++i) {
            stack<int> st;
            for (int j = 0; j < len_matrix.size(); ++j) {
                while (!st.empty() && len_matrix[j][i] < len_matrix[st.top()][i]) {
                    int mid = st.top();
                    st.pop();
                    int h = j - st.top() - 1;
                    int w = len_matrix[mid][i];
                    res = max(res, h * w);
                }
                st.push(j);
            }
        }
        return res;
    }
};