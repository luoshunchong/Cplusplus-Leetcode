// @algorithm @lc id=84 lang=cpp 
// @title largest-rectangle-in-histogram


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([2,1,5,6,2,3])=10
// @test([2,4])=4
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0); // 数组尾部加入元素0
        int result = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int h = heights[mid];
                result = max(result, w * h);
            }
            st.push(i);
        }
        return result;
    }
};