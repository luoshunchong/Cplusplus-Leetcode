/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<int> S;//使用vector数组当作栈来使用
        string result = "";//最终的结果，以string形式输出
        for (int i = 0; i < num.length(); ++i)//从高位遍历num
        {
            int number = num[i] - '0';//将字符型的num数转换为整数
            while (!S.size() && S[S.size() - 1] > number && k > 0)
            //1、栈不空、栈顶元素大于number、还可以移除元素（k>0）
            {
                S.pop_back();//出栈
                k--;
            }
            if (!S.size() || !number)
            {
                S.push_back(number);
            }
        }
        //三种需要考虑的情况
        //1、当栈为空的时候，所有数字都扫描完，还可以删除数字
        while (!S.size() && k > 0)
        {
            S.pop_back();
            k--;
        }
        //2、如何将数字转换成字符串，并存储到result中
        for (int i = 0; i < S.size(); ++i)
        {
            result.append(1, '0' + S[i]);
        }
        //3、当
        if (result == "")
        {
            result = "0";
        }
        return result;
    }
};
// @lc code=end
