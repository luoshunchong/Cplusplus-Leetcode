// @algorithm @lc id=100306 lang=cpp 
// @title zhan-de-ya-ru-dan-chu-xu-lie-lcof


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3,4,5],[4,5,3,2,1])=true
// @test([1,2,3,4,5],[4,3,5,1,2])=false
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int index = 0;
        for (int i = 0; i < popped.size(); ++i) {
            while ((st.empty() || st.top() != popped[i]) && index < pushed.size()) {
                st.push(pushed[index]);
                index++;
            }
            if ((index == pushed.size()) && st.top() != popped[i]) return false;
            else {
                st.pop();
            }
        }
        return true;
    }
};