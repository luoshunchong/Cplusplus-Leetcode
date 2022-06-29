// @algorithm @lc id=1217 lang=cpp 
// @title relative-sort-array


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "algm/algm.h"
using namespace std;
// @test([2,3,1,3,2,4,6,7,9,2,19],[2,1,4,3,9,6])=[2,2,2,1,4,3,3,9,6,7,19]
// @test([28,6,22,8,44,17],[22,28,8,6])=[22,28,8,6,17,44]
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> unmap;
        for (auto num : arr1) {
            if (unmap.count(num)) unmap[num]++;
            else unmap[num] = 1;
        }
        vector<int> temp1;
        for (auto num : arr2) {
            for (int i = 0; i < unmap[num]; ++i) {
                temp1.push_back(num);
            }
            unmap[num] = 0;
        }

        vector<int> temp2;
        for (auto r : unmap) {
            if (r.second) {
                for (int i = 0; i < r.second; ++i) {
                    temp2.push_back(r.first);
                }
            }
        }
        sort(temp2.begin(), temp2.end());
        temp1.insert(temp1.end(), temp2.begin(), temp2.end());
        return temp1;
    }
};