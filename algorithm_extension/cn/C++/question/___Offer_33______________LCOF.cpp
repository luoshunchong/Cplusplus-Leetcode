// @algorithm @lc id=100315 lang=cpp 
// @title er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "algm/algm.h"
using namespace std;
// @test([1,6,3,2,5])=false
// @test([1,3,2,6,5])=true
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> inorder(postorder.begin(), postorder.end());
        sort(inorder.begin(), inorder.end());
        return check(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
    bool check(vector<int>& postorder, vector<int>& inorder, int posl, int posr, int inol, int inor) {
        if (posl > posr || inol > inor) return true;
        int index;
        bool flag = false;
        for (; index <= inor; ++index) {
            if (inorder[index] == postorder[posr]) {
                flag = true;
                break;
            }
        }
        if (!flag) return false;
        //中左
        int inol1 = inol;
        int inor1 = index - 1;
        //中右
        int inol2 = index + 1;
        int inor2 = inor;
        //后左
        int posl1 = posl;
        int posr1 = posl + index - inol - 1;
        //后右
        int posl2 = posl + index - inol;
        int posr2 = posr - 1;
        return check(postorder, inorder, posl1, posr1, inol1, inor1) && check(postorder, inorder, posl2, posr2, inol2, inor2);
    }
};