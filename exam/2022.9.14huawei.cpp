/*
第一题：将起点看成0，中间有n块板子，每次可以跳1/2/3个板子，终点为n+1，有一个初始生命数，有些点的板子是空的，走到上面就会减1条生命。题目求从点0到点n+1的方案数。
输入：
M：生命数 N：板子数量 K：空板子的数量
空板子的编号  

*/
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int res = 0;
unordered_set<int> unse;
unordered_map<string, int> m;

int dfs(int l, int maxD, int re) {
    if (unse.count(l)) re--;
    string key = to_string(l) + "-" + to_string(re);
    if (m.count(key)) {
        res += m[key];
        return m[key];
    }
    if (re == 0) return 0;
    if (l >= maxD) {
        res++;
        return 1;
    }
    int ans = 0;
    for (int i = 1; i < 3 && i + l < maxD + 1; ++i) {
        ans += dfs(l + i, maxD, re);
    }
    m[key] = ans;
    return ans;
}

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    
    for (int i = 0; i < K; ++i) {
        int temp;
        cin >> temp;
        unse.insert(temp);
    }
    dfs(0, N, M);
    return 0;
}
/*
第二题：
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

struct Node{
    int w;
    int t;
};

int check(vector<int>& P, vector<int>& Q, vector<int>& S) {
    int ans = 0;
    sort(P.begin(), P.end());
    vector<Node> A(Q.size());
    for (int i = 0; i < Q.size(); ++i) {
        A[i] = {Q[i], S[i]};
    }
    sort(A.begin(), A.end(), [](const Node& a, const Node& b)->bool {
        return a.t > b.t;
    });
    vector<int> ti(P.size());
    for (int i = 0; i < A.size(); ++i) {
        int pos = lower_bound(P.begin(), P.end(), A[i].w) - P.begin();
        int min_pos = pos;
        for (int j = pos; j < P.size(); ++j) {
            if (ti[j] < ti[min_pos]) min_pos = j;
        }
        ti[min_pos] += A[i].t;
    }
    for (auto &te : ti) {
        ans = max(ans, te);
    }
    return ans;
}

int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    int M, N;
    cin >> M >> N;
    vector<int> P(N), Q(M), S(M);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> Q[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> S[i];
    }
    cout << check(P, Q, S) << endl;
    return 0;
}

/*
第三题：
*/
#include <iostream>
