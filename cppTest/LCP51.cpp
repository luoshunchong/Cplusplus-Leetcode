#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int res = 0;
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        backtracking(materials, cookbooks, attribute, limit, 0, 0, 0);
        return res;
    }
    void backtracking(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit, int b, int m, int pos) {
        for (int i = 0; i < materials.size(); ++i) {
            if (materials[i] < 0) return ;
        }
        if (b >= limit) {
            if (res < m) res = m;
        }
        

        for (int i = pos; i < cookbooks.size(); ++i) {
            for (int j = 0; j < materials.size(); ++j) {
                materials[j] -= cookbooks[i][j];
            }
            b += attribute[i][1];
            m += attribute[i][0];

            backtracking(materials, cookbooks, attribute, limit, b, m , i + 1);

            for (int j = 0; j < materials.size(); ++j) {
                materials[j] += cookbooks[i][j];
            }
            b -= attribute[i][1];
            m -= attribute[i][0];
        }
    }
};

int main() {
    vector<int> materials = {10,10,10,10,10};
    vector<vector<int>> cookbooks = {{1,1,1,1,1},{3,3,3,3,3},{10,10,10,10,10}};
    vector<vector<int>> attribute = {{5,5},{6,6},{10,10}};
    int limit = 1;
    Solution a;
    int res = a.perfectMenu(materials, cookbooks, attribute, limit);
    cout << res << endl;
    return 0;
}