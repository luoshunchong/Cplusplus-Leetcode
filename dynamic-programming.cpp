#include<iostream>
#include<vector>

using namespace std;

void test_ZeroOne_bag(vector<int>& weight,vector<int>& value,int bagsize){
    //初始化
    vector<int> dp(bagszie+1,0);//全部初始化为0就可以了
    for(int i=0;i<weight.size();++i){
        for(int j=bagsize;j>=weight[i];--j){
            dp[j] = max(dp[j],dp[j-])
        }
    }
}

int main(){
    vector<int> weight = {1,3,4};
    vector<int> value = {15,20,30};
    int bagsize = 4;
    //0-1背包

    //完全背包

    system("pause");
    return 0;
}