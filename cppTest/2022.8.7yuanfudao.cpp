// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// /*
// 第一题，组成最大单词数量
// */
// int check(string& s, vector<string>& str) {
//     unordered_map<char, int> unmap;
//     for (auto t : s) unmap[t]++;
//     int res = 0;
//     for (auto t : str) {
//         unordered_map<char, int> unmap1; 
//         for (auto r : t) {
//             if (unmap.count(r) == 0) break;
//             unmap1[r]++;
//         }
//         int temp = 0x3f3f3f3f;
//         for (auto u : unmap1) {
//             temp = min(temp, unmap[u.first] / u.second);
//         }
//         res = max(res, temp);
//     }
//     return res;
// }

// int main() {
//     int M;
//     cin >> M;
//     for (int i = 0; i < M; ++i) {
//         string s;
//         cin.ignore();
//         getline(cin, s);
//         int N;
//         cin >> N;
//         vector<string> str(N, "");
//         for (int j = 0; j < N; ++j) {
//             cin >> str[j];
//         }
//         cout << check(s, str) << endl;
//     }
//     return 0;
// }

/*
第二题，模拟，题目太长，没时间看
*/
// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// int main() {
//     int P;
//     cin >> P;
//     unordered_set<string> hfpy;
//     for (int i = 0; i < P; ++i) {
//         string s;
//         cin >> s;
//         hfpy.insert(s);
//     }
//     unordered_map<char, string> an_shen;
//     unordered_map<char, vector<string> > an_yun;
//     for (int i = 0; i < 26; ++i) {
//         cin.ignore();
//         string s;
//         getline(cin, s);
//         char c = s[0];
//         string t = "";
//         for (int j = 2; j < s.size(); ++j) {
//             if (s[j] == '/') {
//                 an_shen[c] = t;
//                 t = "";
//                 continue;
//             }
//             t.push_back(s[j]);
//         }
//         vector<string> temp;
//         string te = "";
//         for (int j = 0; j < t.size(); ++j) {
//             if (t[j] == ',') {
//                 temp.push_back(te);
//                 te = "";
//                 continue;
//             }
//             te.push_back(t[j]);
//         }
//         temp.push_back(te);
//         an_yun[c] = temp;
//     }
//     unordered_map<string, string> shen_shuang;
//     for (int i = 0; i < 12; ++i) {
//         cin.ignore();
//         string s;
//         getline(cin, s);
//         string te = "";
//         string t = "";
//         string t1 = "";
//         for (int j = 0; j < s.size(); ++j) {
//             if (s[j] == '/' && t == "") {
//                 t = te;
//                 te = "";
//                 break;
//             }
//             te.push_back(s[j]);
//         }
//         t1 = te;
//         shen_shuang[t] = t1;
//     }
//     int N;
//     cin >> N;
//     for (int i = 0; i < N; ++i) {
//         cin.ignore();
//         string s;
//         getline(cin, s);
//         vector<string> res;
//         for (int i = 0; i < s.size(); ++i) {
//             string t = "";
//             if (i & 1) { //奇数
//                 t += an_shen[s[i]];
//             }
//             else {
//                 for (auto y : an_yun[s[i]]) {
//                     if (hfpy.count((t + y))) {
//                         res.push_back((t + y));
//                         break;
//                     }
//                 }
//             }
//         }
//         for (auto r : res) cout << r << " ";
//         cout << endl;
//     }
//     int M;
//     cin >> M;
// //     for (int i = 0; i < M; ++i) {
        
// //     }
//     return 0;
// }

/*
第三题，
*/