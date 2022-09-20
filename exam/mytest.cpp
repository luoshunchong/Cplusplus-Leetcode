// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// void check(vector<int>& nums) {
//     unordered_map<int, int> unmap;
//     for (auto num : nums) unmap[num]++;
//     int res = 0;
//     for (auto num : nums) {
//         res = max(res, unmap[num] + unmap[num - 1] + unmap[num + 1]);
//     }
//     cout << res << endl;
// }

// int main() {

//     vector<int> nums = {1,3};
//     check(nums);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// static bool cmp(vector<int>& a, vector<int>& b) {
//     return a[2] > b[2];
// }

// int check(vector<vector<int>>& nums) {
//     if (nums.size() == 0) return 0;
//     int res = 0;
//     int dis = 1;
//     while (nums.size()) {
//         //更新nums距离
//         for (int i = 0; i < nums.size(); ++i) {
//             nums[i][2] = abs(dis - nums[i][0]) + abs(nums[i][0] - nums[i][1]);
//         }
//         //排序
//         sort(nums.begin(), nums.end(), cmp);
//         //选取最后一个小的元素
//         res += nums[nums.size() - 1][2];
//         dis = nums[nums.size() - 1][1];
//         //删除vector中的最后一个元素
//         nums.pop_back();
//     }
//     return res + dis - 1;
// }

// int main() {
//     int K;
//     cin >> K;
//     vector<vector<int> > nums;
//     for (int i = 0; i< K; ++i) {
//         int a, b;
//         cin >> a >> b;
//         nums.push_back({a, b, 0});
//     }
//     bool flag = false;
//     for (auto num : nums) {
//         if (num[1] > num[0]) {
//             flag = true;
//             break;
//         }
//     }
//     if (!flag) 
//     cout << check(nums) << endl;
//     system("pause");
//     return 0;
// }
/*
5
1 4
3 6
6 3
5 2
7 8

20
*/

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {

//     return 0;
// }

// #include <iostream>
// using namespace std;
// enum class T{
//     A = 0,
//     B,
//     C
// };

// int mian() {
//     int a = T::C;
//     cout << a << endl;
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <stack>
// #include <unordered_set>
// #include <vector>
// using namespace std;

// int res = 0;
// string temp = "";
// vector<string> ve;
// int ishefa(string& s) {
//     if (s.size() <= 1) return 0;
//     int t = 0;
//     stack<char> st;
//     for (int i = 0; i < s.size(); ++i) {
//         if (!st.empty() && s[i] == ')') {
//             st.pop();
//             t += 2;
//             continue;
//         }
//         if (s[i] == '(') st.push(s[i]);
//     }
//     return t;
// }

// int check(string& s) {
//     for (int i = 2; i <= s.size(); ++i) {
//         for (int j = 0; (j + i - 1) < s.size(); ++j) {
//             ve.push_back(s.substr(j, i));
//         }
//     }
//     for (auto u : ve) {
//         res += ishefa(u);
//     }
//     return res;
// }

// int main() {
//     string s;
//     cin >> s;
//     cout << check(s) << endl;
//     return 0;
// }

/*
())())
*/

/*
2022.9.4网易互联网，第四题，求所有子树权值之和
*/
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>

// using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
// };

// int res = 0;

// TreeNode *buildTree(vector<int> &weight, unordered_map<int, vector<int>>& nums) {
//     unordered_map<int, TreeNode*> unmap1;
//     TreeNode* root = new TreeNode(1);
//     TreeNode* p = root;
//     unmap1.insert({1, p});
//     for (int i = 1; i <= (weight.size()); ++i) {
//         p = unmap1[i];
//         if (nums.count(i) == 0) continue;
//         vector<int> temp = nums[i];
//         p->left = new TreeNode(temp[0]);
//         unmap1.insert({temp[0], p->left});
//         if (temp.size() == 2) {
//             p->right = new TreeNode(temp[1]);
//             unmap1.insert({temp[1], p->right});
//         }
//     }
//     return root;
// }

// int get_num(long long n) {
//     int tot = 1;
//     for (int i = 2; i * i <= n; ++i) {
//         if (n % i== 0) {
//             int x = 0;
//             while (n % i == 0) {
//                 n /= i;
//                 x++;
//             }
//             tot *= (x + 1);
//         }
//     }
//     if (n > 1) tot *= 2;
//     return tot;
// }

// int check(vector<int> &weight, TreeNode* root) {
//     if (!root) return 1;
//     int left = check(weight, root->left);
//     int right = check(weight, root->right);
//     long long mul = left * right * weight[root->val - 1];
//     res += get_num(mul);
//     return mul;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> weight(n, 0);
//     for (int i = 0; i < n; ++i) cin >> weight[i];
//     unordered_map<int, vector<int>> unmap;
//     for (int i = 0; i < (n - 1); ++i) {
//         int a, b;
//         cin >> a >> b;
//         unmap[a].push_back(b);
//     }
//     //建树
//     TreeNode *root = buildTree(weight, unmap);
//     check(weight, root);
//     cout << res << endl;
//     return 0;
// }

// /*
// 3
// 1 2 3
// 1 2
// 1 3
// */

// /*
// 一个非空的乱序数组，其中有若干个0，将所有的0，移动到数组末尾
// */
// #include <iostream>
// #include <vector>

// using namespace std;

// void check(vector<int>& nums) {
//     int sum_zero = 0;
//     for (auto num : nums) if (num == 0) sum_zero++;
//     int left = 0, right = 0;
//     for (int i = 0; i < nums.size(); ++i) {
//         if (nums[])
//     }
//     while (right < nums.size()) {
//         if ()
//     }
// }

// int main() {

//     vector<int> nums = {1,0,3,0,5};
//     check(nums);
//     return 0;
// }

// #include <iostream>
// #include <string.h>

// using namespace std;

// void test2() {
//     char string[10], str1[10];
//     int i;
//     for (int i = 0; i < 9; ++i) {
//         str1[i] = 'a';
//     }
//     strcpy(string, str1);
//     for (int i = 0; string[i] != '\0'; ++i) {
//         cout << string[i] << endl;
//     }
    
//     cout << str1 << endl;
// }

// int main() {
//     test2();
//     // CUIntArray array;
//     // array.SetSize(5);
//     // for (int i = 0; i < 5; ++i) {
//     //     array[i] = i + 1;
//     // }
//     // array.SetSize(10);
//     // for (int i = 5; i < 10; ++i) {
//     //     array[i] = i + 1;
//     // }

//     return 0;
// }

// #include <iostream>
// #include <fstream>
// using namespace std;

// struct Date{
//     char mo, da, yr;
// };
// int main() {
//     Date dt1 = {'A','O','a'};
//     ofstream tfile1("data.dat",ios::binary);
//     tfile1 << dt1.mo << dt1.da << dt1.yr;
//     tfile1.close();
//     Date dt2;
//     ifstream tfile2("data.dat", ios::binary);
//     tfile2 >> dt2.mo >> dt2.da >> dt2.yr;
//     cout << dt2.mo << " " << dt2.da << " " << dt2.yr << endl;
//     tfile2.close();
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>

// using namespace std;

// int check1(priority_queue<int, vector<int>, less<int> > &pqu, int m) {
//     int res = 0;
//     bool flag = true;
//     while (true) {
//         vector<int> temp(m);
//         for (int i = 0; i < m; ++i) {
//             if (pqu.empty()) {
//                 flag = false;
//                 break;
//             }
//             int t = pqu.top();
//             pqu.pop();
//             temp[i] = t;
//         }
//         if (!flag) break;
//         for (int i = 0; i < m; ++i) {
//             if (temp[i] - 1 == 0) continue;
//             pqu.push(temp[i] - 1);
//         }
//         res++;
//     }
//     return res;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> nums(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }
//     priority_queue<int, vector<int>, less<int>> pqu;
//     for (auto num : nums) {
//         pqu.push(num);
//     }
//     cout << check1(pqu, m) << endl;
    
//     return 0;
// }
// /*
// 5 3
// 1 2 3 4 5
// */

// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     string s1 = "Chain student";
//     string s2(s1, 6,7);
//     s2.append("program");
//     s2.erase(3);
//     int i = s2.find("stu");
//     cout << i << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int res = 0;

// void resverse1(unordered_map<int, int>& unmap, int max_num, int sum, int root) {
//     if (root > max_num) {
//         res = max(res, sum);
//         return ;
//     }
//     if (unmap.count(root)) sum += unmap[root];
//     resverse1(unmap, max_num, sum, root * 2);
//     resverse1(unmap, max_num, sum, root * 2 + 1);
// }

// int check(unordered_map<int, int>& unmap, int max_num) {
//     resverse1(unmap, max_num, 0, 1);
//     return res;
// }


// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     int max_num = 0;
//     for (int i = 0; i < n; ++i) {
//         int temp;
//         cin >> temp;
//         max_num = max(max_num, temp);
//         nums[i] = temp;
//     }
//     vector<int> value(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> value[i];
//     }
//     unordered_map<int, int> unmap;
//     for (int i = 0; i < nums.size(); ++i) {
//         unmap[nums[i]] = value[i];
//     }
//     cout << check(unmap, max_num) << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// int check(string& s) {
//     vector<int> presum(s.size() + 1);
//     for (int i = 1; i <= s.size(); ++i) {
//         presum[i] = presum[i - 1] + (s[i - 1] -'0');
//     }
//     int res = 0;
//     int index = 0;
//     for (int i = 1; i < presum.size(); ++i) {
//         if ((presum[i] - presum[index]) % 7 == 0) {
//             res++;
//             index = i;
//         }
//     }
//     return res;
// }
// int main() {
//     string s;
//     cin >> s;
//     cout << check(s) << endl;
//     return 0;
// }
/*
输入：
7602661
输出：
3
*/


// int main(){
//     vector<int> nums;
//     int num, k, sum = 0, min_num = INT_MAX;
//     while (cin >> num){
//         nums.push_back(num);
//         sum += num;
//         min_num = min(min_num, num);
//         if (cin.get() == '\n') break;
//     }
//     cin >> k;

//     if(sum < k)
//         cout << 0 << endl;
//     else{
//         int left = 1, right = min_num;
//         while (left < right)
//         {
//             int mid = (left + right + 1) / 2;
//             int res = 0;
//             for (auto &e : nums)
//                 res += e / mid;
//             if (res < k)
//                 right = mid - 1;
//             else
//                 left = mid;
//         }

//         cout << left << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     for (int i = 0; i < t; ++i) {
//         int n;
//         cin >> n;
//         string s1;
//         string s2;
//         cin.ignore();
//         getline(cin, s1);
//         getline(cin, s2);

//         if (s1[0] != s2[0] || s1[n - 1] != s2[n - 1]) {
//             cout << "NO" << endl;
//             continue;
//         }
//         vector<int> dp(n);
//         dp[0] = true;
//         for (int i = 1; i < n; ++i) {
//             if (s1[i] == s2[i]) dp[i] = dp[i - 1];
//             else {
//                 if (dp[i - 1]) {
//                     if (s1[i - 1] != s2[i - 1]) { //前一个交换了
//                         if (s2[i - 1] == s1[i + 1]) dp[i] = false;
//                         else dp[i] = true;
//                     }
//                     else { //没有交换
//                         if (s1[i - 1] == s1[i + 1]) dp[i] = false;
//                         else dp[i] = true;
//                     }   
//                 }
//                 else {
//                     dp[i] = true;
//                 }
//             }
//         }
//         if (dp[n - 1]) cout << "YES" << endl;
//         else cout << "NO" << endl;
//     }
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// struct node_monster{
//     int a;
//     int b;
//     int coin;
// };
// int res = 0;
// int ans = 0;
// int ans1 = 0;
// vector<int> X = {-1, 1, 0, 0};
// vector<int> Y = {0, 0, -1, 1};
// void check(int& A, int B, unordered_map<int, unordered_map<string, int>> &Coins, unordered_map<int, unordered_map<string, node_monster>> &Monsters, int D, int pos, int x, int y, vector<vector<bool>>& used) {
//     if (x < 0 || x >= 6 || y < 0 || y >= 6 || used[x][y]) return ;
//     used[x][y] = true;
//     //遇到金币格子
//     if (Coins.count(pos)) { //有金币格子
//         unordered_map<string, int> coin_temp = Coins[pos];
//         string x_y = to_string(x) + "+" + to_string(y);
//         if (coin_temp.count(x_y)) {
//             ans += coin_temp[x_y];
//         }
//     }
//     //遇到怪物格子
//     if (Monsters.count(pos)) { //有怪物
//         unordered_map<string, node_monster> monster_temp = Monsters[pos];
//         string x_y = to_string(x) + "+" + to_string(y);
//         if (monster_temp.count(x_y)) {
//             //会攻击几次
//             int time = monster_temp[x_y].a / B;
//             if (monster_temp[x_y].a % B) time++;
//             //被怪物打死了
//             if (monster_temp[x_y].b * time >= A) {
//                 //自己死了，野怪还剩多少血
//                 int A_temp = A;
//                 int mon_temp = monster_temp[x_y].a;
//                 while (A_temp > 0) {
//                     A_temp -= monster_temp[x_y].b;
//                     mon_temp -= B;
//                 }
//                 monster_temp[x_y].a = mon_temp;  //更新野怪的血量
//                 //是否要复活
//                 //是
//                 if (ans >= D) {
//                     ans -= D;
//                     A /= 2;
//                     check(A, B, Coins, Monsters, D, pos, x, y, used);
//                 }
                
//                 return ;
//             }
//             else {  //没有被打死
//                 A -= monster_temp[x_y].b * time;
//                 ans += monster_temp[x_y].coin;
//             }   
//         }
//     }
//     //遇到空格子
    

//     for (int i = 0; i < 4; ++i) {
//         int new_x = x + X[i];
//         int new_y = y + Y[i];
//         check(A, B, Coins, Monsters, D, pos, new_x, new_y, used);
//     }
// }

// int main() {
//     int A, B;       //小师妹血量和攻击力
//     cin >> A >> B;
//     int n, m;       //表示10张地图中有n个金币格，m个怪物格
//     cin >> n >> m;
//     unordered_map<int, unordered_map<string, int>> Coins;
//     for (int i = 0; i < n; ++i) {
//         int t, x, y, c;
//         cin >> t >> x >> y >> c;
//         string temp;
//         temp = to_string(x - 1) + "+" + to_string(y - 1);
//         Coins[t - 1].insert({temp, c});
//     }
//     unordered_map<int, unordered_map<string, node_monster>> Monsters;
//     for (int i = 0; i < m; ++i) {
//         int t, x, y, a, b, c;    //血量为a，攻击力为b
//         cin >> t >> x >> y >> a >> b >> c;
//         node_monster temp;
//         temp.a = a;
//         temp.b = b;
//         temp.coin = c;
//         string temp2;
//         temp2 = to_string(x - 1) + "+" + to_string(y - 1);
//         Monsters[t - 1].insert({temp2, temp});
//     }
//     int C, D;
//     cin >> C >> D;  //表示完成一张地图后获得的金币和需要恢复一般血量所需花费的金币
//     vector<int> t;

//     int k = 0;
//     for (int i = 0; i < 6; ++i) {
//         for (int j = 0; j < 6; ++j) {
//             vector<vector<bool>> used(6, vector<bool>(6));
//             check(A, B, Coins, Monsters, D, k, i, j, used);
//             ans1 = max(ans1, ans);
//             ans = 0;
//             //如果全部访问完了，将flag置为true
//             bool flag1 = true;
//             for (int u = 0; u < used.size(); ++u) {
//                 for (int r = 0; r < used[0].size(); ++r) {
//                     if (!used[u][r]) flag1 = false;
//                 }
//             }
//             if (flag1 && k < 10) {
//                 ans1 += C;
//                 t.push_back(ans1);
//                 ans1 = 0;
//                 k++;
//                 i = 0;
//                 j = 0;
//             }
//         }
//     }
    
//     for (auto& a : t) res += a;
    
//     cout << res << endl;  //输出一个数字表示小师妹能够获得的最大金币值
//     return 0;
// }
/*
100 5
2 2
1 1 3 200
2 1 3 200
1 2 1 100 5 100
2 2 1 100 5 200
100 100
*/
