// @algorithm @lc id=77 lang=cpp 
// @title combinations

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    int count = 0;
    void printDebug(int n) {
        for (int i = 0; i < n; ++i) cout << "   " << endl;
    }

    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
    void backtracking(int n, int k, int startIndex) {
        printDebug(++count);
        cout << startIndex << endl;

        if (path.size() == k) {
            result.push_back(path);
            printDebug(--count);
            return;
        }
        for (int i = startIndex; i <= n; ++i) {
            path.push_back(i); // 处理节点 
            backtracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
};