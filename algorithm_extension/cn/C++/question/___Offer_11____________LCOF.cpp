// @algorithm @lc id=100278 lang=cpp 
// @title xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,4,5,1,2])=1
// @test([2,2,2,0,1])=0
// @test([2,0,1,2,2,2])=0
// @test([2,2,1,2,2,2])=1
// @test([2,2,2,2,2,2])=2
// @test([2])=2
class Solution {
public:
    int minArray(vector<int>& numbers) {
        //二分法,左闭右闭
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (numbers[mid] > numbers[right]) left = mid + 1;
            else if (numbers[mid] < numbers[right]) right = mid;
            else right -= 1;
        }
        return numbers[left];
    }
};