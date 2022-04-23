#include <iostream>
#include <string>

using namespace std;

int main() {
    int a = 8765;
    //int转换成string
    string str = to_string(a);
    //string转换成int
    int b = stoi(str.c_str());

    cout << str << endl;
    cout << b << endl;

    string temp = "01";
    int c = stoi(temp);
    cout << c << endl;
    return 0;
}