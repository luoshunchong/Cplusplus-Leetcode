// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution
{
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() > 12)
            return res;
        backtracking(s, 0, 0);
        return res;
    }
    void backtracking(string s, int pos, int num)
    {
        //使用num来控制'.'的个数
        if (num == 3)
        {
            if(Is_Num(s,pos,s.size()-1)){
                res.push_back(s);
            }
            return;
        }
        for (int i = pos; i < s.size(); ++i)
        {
            if (Is_Num(s, pos, i))//判断[pos,i]是否合法
            {//在同一个字符串上操作
                s.insert(s.begin()+i+1,'.');
                num++;
                backtracking(s,i+2,num);
                num--;
                s.erase(s.begin()+i+1);
            }
            else break;
        }
    }
    bool Is_Num(string s, int pos, int i)
    {
        if (pos > i)
            return false;
        if (s[pos]=='0'&&pos!=i)
        {
            return false;
        }
        int nums=0;
        for(int j=pos;j<=i;++j){
            if(s[j]>'9'||s[j]<'0'){
                return false;
            }
            nums = nums*10+(s[j]-'0');
            if(nums>255){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
