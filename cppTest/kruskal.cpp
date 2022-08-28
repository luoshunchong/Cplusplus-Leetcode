#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int start;
    int end;
    int length;
};
bool cmp(node a, node b) {
    return a.length < b.length;
}

int father[99999];
int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

int kruskal(vector<node>& edge) {
    int N = edge.size();
    for (int i = 0; i < N; ++i) {
        father[i] = i;
    }
    sort(edge.begin(), edge.end(), cmp);
    int weight = 0;
    int Num_Edge = 0;
    for (int i = 0; i < N; ++i) {
        int faU = findFather(edge[i].start);
        int faV = findFather(edge[i].end);
        if (faU != faV) {
            father[faU] = faV;
            weight += edge[i].length;
            Num_Edge++;
            if (Num_Edge == N - 1) break;
        }
    }
    if (Num_Edge != N - 1) return -1; //无法连通时，返回-1
    else return weight; //返回最小生成树的边权重之和
}

int main() {
    vector<node> edge = {{1,2,885},{1,3,513},{2,3,817}}; //{start, end, length}
    cout << kruskal(edge) << endl;
    return 0;
}