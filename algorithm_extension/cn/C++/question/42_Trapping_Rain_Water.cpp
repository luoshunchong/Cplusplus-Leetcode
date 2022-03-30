// @algorithm @lc id=42 lang=cpp 
// @title trapping-rain-water


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include "algm/algm.h"
using namespace std;
// @test([0,1,0,2,1,0,1,3,2,1,2,1])=6
// @test([4,2,0,3,2,5])=9
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
            }
            st.push(i);
        }
        return sum;
    }
};