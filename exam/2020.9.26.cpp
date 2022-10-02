class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @param x int整型 
     * @return int整型
     */
    int getSubarrayNum(vector<int>& a, int x) {
        // write code here
        int res = 0;
        vector<long long> premul(a.size());
        premul[0] = a[0];
        for (int i = 1; i < a.size(); ++i) {
            premul[i] = premul[i - 1] * a[i];
        }
        for (int i = 0; i < premul.size(); ++i) {
            for (int j = i; j < premul.size(); ++j) {
                if (i == 0) {
                    if (check(premul[j], x)) res++;
                }
                else {
                    premul[j] /= premul[j - 1];
                    if (check(premul[j], x)) res++;
                }
            }
        }
        return res;
    }
    bool check(int num, int x) {
        int res = 0;
        while (num) {
            int a = num % 10;
            if (a == 0) res++;
            if (res >= x) return true;
            if (a != 0 && res < x) return false;
            num /= 10;
        }
        return false;
    }
};