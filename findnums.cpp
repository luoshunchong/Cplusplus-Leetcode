#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fintwonums(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> left;
        vector<int> right;
        int sumleft = 0;
        int sumright = 0;
        int i = 0;
        sort(nums.begin(), nums.end()); //{1,3,4,5,6,7}
        while (i < nums.size())
        {
            int temp1 = nums[i] >= nums[i + 1] ? nums[i + 1] : nums[i];
            int temp2 = nums[i] + nums[i + 1] - temp1;
            if (sumleft >= sumright)
            {
                left.push_back(temp1);
                sumleft += temp1;
                right.push_back(temp2);
                sumright += temp2;
            }
            else
            {
                right.push_back(temp1);
                sumright += temp1;
                left.push_back(temp2);
                sumleft += temp2;
            }
            i += 2;
        }
        //判断是不是奇数个数
        if (nums.size() % 2 != 0)
        {
            if (sumleft >= sumright)
            {
                right.push_back(nums[i - 1]);
                sumright += nums[i - 1];
            }
            else
            {
                left.push_back(nums[i - 1]);
                sumleft += nums[i - 1];
            }
        }
        if (sumleft == sumright)
        {
            res.push_back(left);
            res.push_back(right);
        }
        return res;
    }
    
    //回溯法
    vector<vector<int>> res;
    vector<int> ve;
    int sumall=0;
    int sumleft=0;
    bool b=false;
    vector<vector<int>> fintwonums1(vector<int> &nums){
        vector<bool> ve1(nums.size(), false);//用于判断ve是否使用了该元素
        for(int i=0;i<nums.size();++i){
            sumall+=nums[i];
        }
        if(sumall%2!=0){//判断所有数的总和是不是偶数，不是的话就没必要继续了
            return res;
        }else{
            backtracking(nums, ve1, 0);
            return res;
        }
    }
    void backtracking(vector<int>& nums,vector<bool>& ve1, int pos){
        if(sumall/2==sumleft){
            res.push_back(ve);
            vector<int> right;
            for(int j=0;j<ve1.size();++j){
                if(ve1[j]==false){
                    right.push_back(nums[j]);
                }
            }
            res.push_back(right);
            b = true;
            return;
        }
        if(sumleft>sumall/2) return;
        for(int i=pos;i<nums.size();++i){
            if(b==false){
                sumleft+=nums[i];
                ve.push_back(nums[i]);
                ve1[i] = true;
                backtracking(nums,ve1,i+1);
                sumleft-=nums[i];
                ve.pop_back();
                ve1[i] = false;
            }else{
                break;
            }
        }
    }
};

int main()
{
    Solution a;
    vector<int> nums = {1, 5, 6, 7, 4, 2, 1};
    vector<vector<int>> res = a.fintwonums1(nums);
    if (res.size() == 0)
    {
        cout << "不存在！" << endl;
    }
    else
    {
        for (int i = 0; i < res.size(); ++i)
        {
            cout << endl;
            for (int j = 0; j < res[i].size(); ++j)
            {
                cout << res[i][j];
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}