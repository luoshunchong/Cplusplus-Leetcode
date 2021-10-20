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
        int i=0;
        sort(nums.begin(), nums.end()); //{1,3,4,5,6,7}
        while(i<nums.size()){
            if(sumleft>=sumright){
                int temp1=nums[i]>=nums[i+1]?nums[i+1]:nums[i];
                left.push_back(temp1);
                sumleft+=temp1;
                int temp2=nums[i]+nums[i+1]-temp1;
                right.push_back(temp2);
                sumright+=temp2;
            }else{
                int temp1 = nums[i] >= nums[i + 1] ? nums[i + 1] : nums[i];
                right.push_back(temp1);
                sumright += temp1;
                int temp2 = nums[i] + nums[i + 1] - temp1;
                left.push_back(temp2);
                sumleft += temp2;
            }
            i+=2;
        }
        if (sumleft == sumright)
        {
            res.push_back(left);
            res.push_back(right);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> nums = {1, 5, 6, 7, 4, 3};
    vector<vector<int>> res = a.fintwonums(nums);
    for (int i = 0; i < res.size(); ++i)
    {
        cout<<endl;
        for (int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j];
        }
    }
    system("pause");
    return 0;
}