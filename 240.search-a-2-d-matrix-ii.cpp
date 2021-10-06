/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left_h = 0, right_h = matrix[0].size() - 1, left_s = 0, right_s = matrix.size() - 1;
        int mid1 = 0, mid2 = 0;
        while (1)
        {
            if (left_h <= right_h)
            {
                if ((left_h + right_h) % 2 == 0)
                    mid1 = (left_h + right_h) / 2;
                else
                    mid1 = (left_h + right_h + 1) / 2;
                if (matrix[mid2][mid1] > target)
                    left_h = mid1 + 1;
                if (matrix[mid2][mid1] < target)
                    right_h = mid1 - 1;
                if (matrix[mid2][mid1] == target)
                {
                    return true;
                    break;
                }
            }
            if (left_s <= right_s)
            {
                if ((left_s + right_s) % 2 == 0)
                    mid2 = (left_s + right_s) / 2;
                else
                    mid2 = (left_s + right_s + 1) / 2;
                if (matrix[mid2][mid1] > target)
                    left_s = mid2 + 1;
                if (matrix[mid2][mid1] < target)
                    right_s = mid2 - 1;
                if (matrix[mid2][mid1] == target)
                {
                    return true;
                    break;
                }
            }
            if (left_h > right_h && left_s > right_s)
            {
                return false;
                break;
            }
        }
    }
};
// @lc code=end

