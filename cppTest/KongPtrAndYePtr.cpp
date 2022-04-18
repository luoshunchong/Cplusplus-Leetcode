#include <iostream>

using namespace std;

int main() {
    //野指针
    // int *p;
    // cout << *p << endl;
    //悬空指针
    int *t = nullptr;
    int *p2 = new int(1);

    cout << (int*)t << endl;
    cout << (int*)p2 << endl;

    cout << &p2 << endl;

    t = p2;
    
    cout << &t << endl;

    delete p2;

    cout << &p2 << endl;

    return 0;
}