/*
第一题：将起点看成0，中间有n块板子，每次可以跳1/2/3个板子，终点为n+1，有一个初始生命数，有些点的板子是空的，走到上面就会减1条生命。
题目求从点0到点n+1的方案数。
输入：
M：生命数 N：板子数量 K：空板子的数量
空板子的编号  

*/
// #include <iostream>
// #include <unordered_set>
// #include <unordered_map>

// using namespace std;

// //采用记忆化搜索的方式来写

// int res = 0;
// unordered_set<int> unse;       //存储缺失木板的位置
// unordered_map<string, int> m;  //记忆数组

// //     当前的位置，最远的位置，生命数   返回当前位置到最远位置的方案数
// int dfs(int l, int maxD, int re) {
//     if (unse.count(l)) re--;                           //如果当前位置是缺失木板，生命值减一
//     string key = to_string(l) + "-" + to_string(re);   //用当前位置和剩余生命数，构建记忆化搜索
//     if (m.count(key)) {                                //如果记忆数组中存在值，则不用递归了，直接返回值
//         res += m[key];
//         return m[key];
//     }
//     if (re == 0) return 0;                             //生命数为0，走不了了
//     if (l >= maxD) {                                   //走到最终的位置了
//         res++;
//         return 1;
//     }
//     int ans = 0;
//     for (int i = 1; i < 3 && i + l < maxD + 1; ++i) {  //选择走1步，2步，3步？
//         ans += dfs(l + i, maxD, re);
//     }
//     m[key] = ans;
//     return ans;
// }

// int main() {
//     int M, N, K;          //M表示生命值，N表示木板的条数，K表示缺失木板的位置
//     cin >> M >> N >> K;
    
//     for (int i = 0; i < K; ++i) {
//         int temp;
//         cin >> temp;
//         unse.insert(temp);
//     }
//     dfs(0, N, M);
//     return 0;
// }

/*
第二题：m个通道发n个文件,可以同时发送,通道有大小,文件有大小,耗时,  求发送完所有文件最小耗时
*/
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// // we have defined the necessary header files here for this problem.
// // If additional header files are needed in your program, please import here.

// struct Node{
//     int w;
//     int t;
// };
// //先发耗时最大的文件,找一个最空闲的并且大于文件的通道发送
// //           通道的大小，  每个包的大小，   每个包发送出去的时间
// int check(vector<int>& P, vector<int>& Q, vector<int>& S) {
//     int ans = 0;
//     sort(P.begin(), P.end());  //通道排序
//     vector<Node> A(Q.size());  //构建<包大小，发送时间>
//     for (int i = 0; i < Q.size(); ++i) {
//         A[i] = {Q[i], S[i]};
//     }
//     sort(A.begin(), A.end(), [](const Node& a, const Node& b)->bool {
//         return a.t > b.t;
//     });                        //对A按照发送时间排序,由大到小排序
//     vector<int> ti(P.size());  //存放每个通道目前花费的时间
//     for (int i = 0; i < A.size(); ++i) {   //依次遍历每个包
//         int pos = lower_bound(P.begin(), P.end(), A[i].w) - P.begin(); //找到能够发送包的最小通道的下标
//         int min_pos = pos;
//         for (int j = pos; j < P.size(); ++j) {     //寻找花费时间最短的通道
//             if (ti[j] < ti[min_pos]) min_pos = j;
//         }
//         ti[min_pos] += A[i].t;                    //在该通道中发送，并累加时间
//     }
//     for (auto &te : ti) {
//         ans = max(ans, te);
//     }
//     return ans;
// }

// int main()
// {
//     // please define the C++ input here. For example: int a,b; cin>>a>>b;;
//     // please finish the function body here.
//     // please define the C++ output here. For example:cout<<____<<endl;
//     int M, N;
//     cin >> M >> N;
//     vector<int> P(N), Q(M), S(M);
//     for (int i = 0; i < N; ++i) {
//         cin >> P[i];
//     }
//     for (int i = 0; i < M; ++i) {
//         cin >> Q[i];
//     }
//     for (int i = 0; i < M; ++i) {
//         cin >> S[i];
//     }
//     cout << check(P, Q, S) << endl;
//     return 0;
// }
/*
5 2        //5个包, 2个通道
100 100    //两个通道的大小
7 6 4 3 2  //每个包的大小
7 6 4 3 2  //每个包发送出去的时间
*/

/*
第三题： ip寻址, 有ttl限制,求从发送路由到接收路由的最短路径

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct node{
    int n;
    int val;
    node(int n1, int val1):n(n1), val(val1) {};
};

int res = INT32_MAX;
void dfs(unordered_map<int, vector<node>> mp, int begin, unordered_set<int>& visit, int end, int& lenmin, int len, int& mincost, int cost, int ttl) {
    if (len > lenmin || cost > mincost || cost > ttl) return ;   //当前的距离比最小距离要大，当前TTL比最小TTL大，当前的TTL比阈值大。都直接返回
    if (begin == end) {  //到达终点了
        if (len == lenmin) mincost = min(mincost, cost);   //当前的距离和最小距离一样，只需要更新TTL就可以了
        else if (len < lenmin) {     //当前的距离比最小距离小，需要更新TTL和当前距离
            lenmin = len;  
            mincost = cost;
        }
        return ;
    }
    for (auto& nod : mp[begin]) {
        if (visit.count(nod.n)) continue;
        visit.insert(nod.n);
        dfs(mp, nod.n, visit, end, lenmin, len + nod.val, mincost, cost + 1, ttl);
        visit.erase(nod.n);
    }
}

int main() {
    int n, id1, id2, ttl;
    cin >> n >> id1 >> id2 >> ttl;
    unordered_map<int, vector<node>> mp;
    int a, b, val;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> val;
        mp[a].emplace_back(node(b, val));
        mp[b].emplace_back(node(a, val));
    }
    if (mp.count(id1) == 0 || mp.count(id2) == 0) {
        cout << -1 << endl;
        return 0;
    }
    unordered_set<int> visit;
    int lenmin = INT32_MAX, len = 0;     //lenmin表示最小距离，len表示当前的距离
    int mincost = INT32_MAX, cost = 0;   //mincost表示最小TTL次数，cost表示当前TTL时间
    dfs(mp, id1, visit, id2, lenmin, len, mincost, cost, ttl);
    if (mincost == INT32_MAX || mincost > ttl) cout << -1 << endl;
    else cout << lenmin << " " << ttl - mincost << endl;
    return 0;
}
/*
N begin end TTL  //路由器个数，开始路由器，结束路由器，TTL时间
a b val          //路由器a到b，val表示路路径
*/
