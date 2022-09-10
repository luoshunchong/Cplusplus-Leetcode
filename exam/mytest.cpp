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