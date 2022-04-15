#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "I am a s and am a b";
    cout << "原始字符串：" << s << endl;
    //截取子字符串，从第1个字符开始截取长度为6的子字符串
    cout << "s1.substr(10, 6) = " << s.substr(1, 6) << endl;  

    //寻找子字符串的位置
    cout << "s2.find(am) = " << s.find("am") << endl;   
    //从字符串末尾开始寻找
    cout << "s2.rfind(am) = " << s.rfind("am") << endl; 
    
    //删除子字符串，从第3个字符开始删除长度为5的子字符串，调用之后会直接改变原字符串
    cout << "s3.erase(3, 5) = " << s.erase(3, 5) << endl; 

    //替换子字符串，从第3个字符开始替换长度为2的子字符串，调用之后会直接改变原字符串
    cout << "s4.replace(3, 2) = " << s.replace(3, 2, "HHHHH") << endl; 

    //插入子字符串，从第3个字符开始插入子字符串，调用之后会直接改变原字符串
    cout << "s5.insert(3, \"lucky\") = " << s.insert(3, "lucky") << endl;

    return 0;
}