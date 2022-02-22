#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
打印数组
*/
void printArray(vector<int>& nums) {
    for (auto a : nums) {
        cout << a ;
    }
    cout << endl;
}

/*
构建测试用例
*/
vector<int> buildTestCase(int num) {
    vector<int> res;
    for (int i = 0; i < num; ++i) {
        res.push_back(i);
    }
    random_shuffle(res.begin(), res.end());
    return res;
}