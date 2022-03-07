#include <iostream>
#include <string> 

using namespace std;

int main() {
    string str = "Ab";
    char ch = 'a';
    //大写转小写
    string low_str = str;
    for (auto &t:low_str) {
        if (t > 64 && t < 91) {
            t += 32;
        }
    }
    //小写转大写
    string up_str = str;
    for (auto &t:up_str) {
        if (t > 96 && t < 123) {
            t -= 32;
        }
    }

    //使用函数实现
    //如果是字符的话使用<ctype.h>中的toupper(),tolower()
    char up_ch = toupper(ch);

    cout << low_str << endl;
    cout << up_str << endl;
    cout << up_ch << endl;
    return 0;
}