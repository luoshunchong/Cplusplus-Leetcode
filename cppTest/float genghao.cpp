#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    cin >> x; //输出x

    double l = 0, r;

    if (x > 1)
        r = x;
    else
        r = 1;

    while (r - l > 1e-8) { //取决于要求的精度
        double mid = (l + r) / 2;
        // if (mid * mid >= x)
        if (mid >= x / mid)
            r = mid;
        else
            l = mid;
    }

    cout << l << endl;

    //保留精度的写法
    printf("%.6f", l); //保留6位有效数字
    cout << endl;

    //对比
    cout << sqrt(x) << endl;
    return 0;
} //该代码来自AcWing网站
