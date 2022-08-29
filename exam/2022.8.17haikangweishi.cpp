/*
只有一题，求最小生成树。
题目是：有一个村庄，n户人家，m条路，要对m条路修路。问最小花费是多少？
输入是：
每个用例一行，第一个数字表示n,第二个数字表示m,后面的数组a表示,a[0]表示起始村庄，a[1]表示结束村庄,a[2]表示修路的花费
3,3,[[1,3,3],[1,2,1],[2,3,1]]

输出：
2

可以使用克里斯卡尔算法（kruskal）
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//split算法,以逗号来进行分割
vector<string> split(string& str, char sub_str) {
    vector<string> res;
    string t = "";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == sub_str) {
            res.push_back(t);
            t = "";
        }
        else {
            if (isdigit(str[i])) t.push_back(str[i]);
        }
    }
    if (t.size() != 0) res.push_back(t);
    return res;
}

struct Node { //作为数据结构存储图
    int start;
    int end;
    int length;
};
bool compare(Node a, Node b) {
    return a.length < b.length;
}
void Kruskal(vector<Node> &arr, vector<bool> &visited) {
    int M = visited.size();
    int N = arr.size();
    sort(arr.begin(), arr.end(), compare);
    int weight = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[arr[i].start] || !visited[arr[i].end]) {
            weight += arr[i].length;
            visited[arr[i].start] = true;
            visited[arr[i].end] = true;
        }
    }
    cout << "最小生成树权值为:";
    cout << weight << endl;
}

int main() {
    int n, m;
    string str;
    getline(cin, str);
    vector<string> temp = split(str, ',');
    n = stoi(temp[0]);
    m = stoi(temp[1]);
    vector<Node> nums;
    for (int i = 2; i < m * 3; i += 3) {
        nums.push_back({stoi(temp[i]), stoi(temp[i + 1]), stoi(temp[i + 2])});
    }
    vector<bool> used(n, 0);
    Kruskal(nums, used);
    return 0;
}

