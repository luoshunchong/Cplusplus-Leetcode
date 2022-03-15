#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    { //官方解答
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};

int main(){
    Solution s;
    vector<int> res = { 4,1,4,6 };

    vector<int> t = s.singleNumbers(res);
    for(int i=0;i<t.size();++i){
        cout<<t[i]<<endl;
    }

    system("pause");
    return 0;
}