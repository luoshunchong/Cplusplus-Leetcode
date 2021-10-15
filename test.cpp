#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int main()
{
    // int a = 10;
    // int b = 20;
    // int &c = a; //相当于个a去了一个别名，a的别名是c，a与c的地址实际上是一样的。
    // c = b;
    // cout << c << endl;
    // cout << &c << &a << endl; //取地址的方法

    unordered_map<int,int> ma;
    ma.insert(make_pair(2,3));
    int t = ma[2];
    cout<<t<<endl;
}
