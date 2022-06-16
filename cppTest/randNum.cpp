#include <iostream>

using namespace std;

int main() {
    int randnum1 = rand();
    cout << "生成一个随机数：" << randnum1 << endl;
    int randnum2 = rand() % 10;
    cout << "产生1~10之间的随机整数:" << randnum2 << endl;
    cout << RAND_MAX << endl;
    return 0; 
}