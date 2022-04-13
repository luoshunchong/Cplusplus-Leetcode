// @algorithm @lc id=100308 lang=cpp 
// @title zi-fu-chuan-de-pai-lie-lcof


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "algm/algm.h"
using namespace std;
// @test("abc")=["abc","acb","bac","bca","cab","cba"]
// @test("aab")=["aba","aab","baa"]
// @test("suvyls")=["lsusvy","lsusyv","lsuvsy","lsuvys","lsuysv","lsuyvs","lsvsuy","lsvsyu","lsvusy","lsvuys","lsvysu","lsvyus","lsysuv","lsysvu","lsyusv","lsyuvs","lsyvsu","lsyvus","lssuvy","lssuyv","lssvuy","lssvyu","lssyuv","lssyvu","lusvsy","lusvys","lusysv","lusyvs","lussvy","lussyv","luvsys","luvssy","luvyss","luysvs","luyssv","luyvss","lvsusy","lvsuys","lvsysu","lvsyus","lvssuy","lvssyu","lvusys","lvussy","lvuyss","lvysus","lvyssu","lvyuss","lysusv","lysuvs","lysvsu","lysvus","lyssuv","lyssvu","lyusvs","lyussv","lyuvss","lyvsus","lyvssu","lyvuss","slsuvy","slsuyv","slsvuy","slsvyu","slsyuv","slsyvu","slusvy","slusyv","sluvsy","sluvys","sluysv","sluyvs","slvsuy","slvsyu","slvusy","slvuys","slvysu","slvyus","slysuv","slysvu","slyusv","slyuvs","slyvsu","slyvus","sulsvy","sulsyv","sulvsy","sulvys","sulysv","sulyvs","suslvy","suslyv","susvly","susvyl","susylv","susyvl","suvlsy","suvlys","suvsly","suvsyl","suvyls","suvysl","suylsv","suylvs","suyslv","suysvl","suyvls","suyvsl","svlsuy","svlsyu","svlusy","svluys","svlysu","svlyus","svsluy","svslyu","svsuly","svsuyl","svsylu","svsyul","svulsy","svulys","svusly","svusyl","svuyls","svuysl","svylsu","svylus","svyslu","svysul","svyuls","svyusl","sylsuv","sylsvu","sylusv","syluvs","sylvsu","sylvus","sysluv","syslvu","sysulv","sysuvl","sysvlu","sysvul","syulsv","syulvs","syuslv","syusvl","syuvls","syuvsl","syvlsu","syvlus","syvslu","syvsul","syvuls","syvusl","ssluvy","ssluyv","sslvuy","sslvyu","sslyuv","sslyvu","ssulvy","ssulyv","ssuvly","ssuvyl","ssuylv","ssuyvl","ssvluy","ssvlyu","ssvuly","ssvuyl","ssvylu","ssvyul","ssyluv","ssylvu","ssyulv","ssyuvl","ssyvlu","ssyvul","ulsvsy","ulsvys","ulsysv","ulsyvs","ulssvy","ulssyv","ulvsys","ulvssy","ulvyss","ulysvs","ulyssv","ulyvss","uslsvy","uslsyv","uslvsy","uslvys","uslysv","uslyvs","usvlsy","usvlys","usvsly","usvsyl","usvyls","usvysl","usylsv","usylvs","usyslv","usysvl","usyvls","usyvsl","usslvy","usslyv","ussvly","ussvyl","ussylv","ussyvl","uvlsys","uvlssy","uvlyss","uvslsy","uvslys","uvsyls","uvsysl","uvssly","uvssyl","uvylss","uvysls","uvyssl","uylsvs","uylssv","uylvss","uyslsv","uyslvs","uysvls","uysvsl","uysslv","uyssvl","uyvlss","uyvsls","uyvssl","vlsusy","vlsuys","vlsysu","vlsyus","vlssuy","vlssyu","vlusys","vlussy","vluyss","vlysus","vlyssu","vlyuss","vslsuy","vslsyu","vslusy","vsluys","vslysu","vslyus","vsulsy","vsulys","vsusly","vsusyl","vsuyls","vsuysl","vsylsu","vsylus","vsyslu","vsysul","vsyuls","vsyusl","vssluy","vsslyu","vssuly","vssuyl","vssylu","vssyul","vulsys","vulssy","vulyss","vuslsy","vuslys","vusyls","vusysl","vussly","vussyl","vuylss","vuysls","vuyssl","vylsus","vylssu","vyluss","vyslsu","vyslus","vysuls","vysusl","vysslu","vyssul","vyulss","vyusls","vyussl","ylsusv","ylsuvs","ylsvsu","ylsvus","ylssuv","ylssvu","ylusvs","ylussv","yluvss","ylvsus","ylvssu","ylvuss","yslsuv","yslsvu","yslusv","ysluvs","yslvsu","yslvus","ysulsv","ysulvs","ysuslv","ysusvl","ysuvls","ysuvsl","ysvlsu","ysvlus","ysvslu","ysvsul","ysvuls","ysvusl","yssluv","ysslvu","yssulv","yssuvl","yssvlu","yssvul","yulsvs","yulssv","yulvss","yuslsv","yuslvs","yusvls","yusvsl","yusslv","yussvl","yuvlss","yuvsls","yuvssl","yvlsus","yvlssu","yvluss","yvslsu","yvslus","yvsuls","yvsusl","yvsslu","yvssul","yvulss","yvusls","yvussl"]
class Solution {
public:
    vector<string> res;
    string temp = "";
    vector<string> permutation(string s) {
        //回溯法
        if (s.size() == 0) return {};
        vector<bool> used(s.size(), false);
        sort(s.begin(), s.end());
        backtracking(s, used);
        return res; 
    }
    void backtracking(string s, vector<bool>& used) {
        if (temp.size() == s.size()) {
            res.push_back(temp);
            return ;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;
            if (!used[i]) {
                used[i] = true;
                temp.push_back(s[i]);
                backtracking(s, used);
                used[i] = false;
                temp.erase(temp.size() - 1);
            }
        }
    }
};