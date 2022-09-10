/*
 三个数的最小公倍数
*/
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

void check(int a, int b, int c) {
    int gcd_ab = gcd(a, b);
    cout << (a * b * c) / (gcd_ab * gcd(a * b / gcd_ab, c)) << endl;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    check(a, b, c);
    return 0;
}

/*
三数之和
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 找出并返回满足条件且不重复的三元组
     * @param nums int整型vector 包含n个整数的数组nums
     * @param target int整型 目标值
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeSum(vector<int>& nums, int target) {
        // write code here
        if (nums.size() < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > target) right--;
                else if (nums[i] + nums[left] + nums[right] < target) left++;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (nums[left] == nums[left + 1] && left + 1 < right) left++;
                    while (nums[right] == nums[right - 1] && right -1 > left) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

/*
 小鸟选树洞
*/
#include <iostream>
#include <vector>

using namespace std;

float eps = 1e-8;

bool judge(int k, int n, float p) {
    float my_p = 1.0;
    for (int i = 1; i <= k; ++i) {
        my_p *= ((n - i + 1) / (n * 1.0));
    }
    my_p = 1 - my_p;
    if (my_p > (p - eps)) return true;
    else return false;
}

void check(int n, float p) {
    int left = 2, right = n + 1;
    while (left < right) {
        int k = left + (right - left) / 2;
        if (judge(k, n, p)) right = k;
        else left = k + 1;
    }
    cout << left << endl;
}

int main() {
    int n;
    float p;
    cin >> n >> p;
    check(n, p);
    return 0;
}