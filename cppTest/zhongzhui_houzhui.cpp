#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <string>
 
using namespace std;

int evalRPN(vector<string>& tokens) {
    //使用栈模拟实现
    stack<string> st;
    for (int i = 0; i < tokens.size(); ++i) {
        int a, b;
        string t = tokens[i];
        if (t == "+") {
            a = stoi(st.top());
            st.pop();
            b = stoi(st.top());
            st.pop();
            st.push(to_string(b + a));
        }
        else if (t == "-") {
            a = stoi(st.top());
            st.pop();
            b = stoi(st.top());
            st.pop();
            st.push(to_string(b - a));
        }
        else if (t == "*") {
            a = stoi(st.top());
            st.pop();
            b = stoi(st.top());
            st.pop();
            st.push(to_string(b * a));
        }
        else if (t == "/") {
            a = stoi(st.top());
            st.pop();
            b = stoi(st.top());
            st.pop();
            st.push(to_string(b / a));
        }
        else {
            st.push(t);
        }
    }
    return stoi(st.top());
}
 
int priority(string op) {
    int priority;
    if(op == "*" || op == "/") priority = 2;
    if(op == "+" || op == "-") priority = 1;
    if(op == "(") priority = 0;
    return priority;
}
 
//引用符号提高转换效率
void Trans(vector<string> &str, vector<string> &str1) {
    stack<string> s;
    int i;
    for(i = 0; i < str.size(); i ++ ) {
        //是数字的情况下直接输出
        if(str[i] >= "0" && str[i] <= "9" || str[i] >= "a" && str[i] <= "z") {
            str1.push_back(str[i]);
        }
        else { //不是数字的情况分类讨论进行判断
            //栈为空时直接入栈
            if(s.empty()) s.push(str[i]);
            //左括号入栈
            else if(str[i] == "(") s.push(str[i]);
            //如果是右括号，只要栈顶不是左括号，就弹出并输出
            else if(str[i] == ")") {
                while(s.top() != "(") {
                    str1.push_back(s.top());
                    s.pop();
                }
                //弹出左括号，但不输出
                s.pop();
            }
            else {
                //栈顶元素的优先级大于等于当前的运算符，就将其输出
                while(priority(str[i]) <= priority(s.top())) {
                    str1.push_back(s.top());
                    s.pop();
                    //栈为空，停止
                    if(s.empty()) break;
                }
                s.push(str[i]);
            }
        }
    }
    //最后，如果不为空，就把所以的元素全部弹出
    while(!s.empty()) {
        str1.push_back(s.top()); 
        s.pop();
    }
}
 
int main() {
    //输入前缀表达式
    string infix;
    cin >> infix;
    //数据预处理
    //处理括号问题
    for (auto& i : infix) {
        if (i == '[') i = '(';
        else if (i == ']') i = ')';
        else if (i == '{') i = '(';
        else if (i == '}') i = ')';
    }
    //处理正负号问题
    vector<string> temp;
    string temp1 = "";
    for (int i = 0; i < infix.size(); ++i) {
        if ((infix[i] == '+' || infix[i] == '-') && infix[i - 1] == '(') {
            temp.push_back('0');
        }
        temp.push_back(infix[i]);
    }
    vector<string> postfix;
    Trans(temp, postfix);

    

    cout << evalRPN(postfix) << endl;
    return 0;
}