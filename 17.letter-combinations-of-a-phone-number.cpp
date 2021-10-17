// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> res;//最终结果
    vector<string> let{//使用二维数组存储字符串，也可以使用map来存
        "",
        "",
        "abc",
        "def",
        "ghi", 
        "jkl", 
        "mno", 
        "pqrs", 
        "tuv", 
        "wxyz"
        }; //存放数字到字母的映射
    string st = "";//临时string
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        backtracking(digits,0);
        return res;
    }
    void backtracking(string digits, int pos){
        if(pos==digits.size()){
            res.push_back(st);
            return ;
        }
        int digit = digits[pos]-'0';//将char的数字转换成int
        string letters = let[digit];
        for(int i=0;i<letters.size();++i){
            st.push_back(letters[i]);
            backtracking(digits,pos+1);
            st.pop_back();
        }
    }
};
// @lc code=end

