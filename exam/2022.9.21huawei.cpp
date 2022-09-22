#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    unordered_map<string, vector<string>> bgp_area;
    unordered_map<string, vector<string>> area_ip;
    unordered_set<string> unse;
    string s;
    string bg;
    string ar;
    vector<string> are;
    vector<string> ip;
    while (s != "#") {
        getline(cin, s);
        if (s[0] == 'b') {
            if (bg.size()) {
                bgp_area.insert({bg, are});
                bg = "";
                are.clear();
            }
            bg = s;
        }
        else if (s[0] == 'a') {
            if (ar.size()) {
                area_ip.insert({ar, ip});
                ar = "";
                ip.clear();
            }
            ar = s;
            are.push_back(ar);
        }
        else if (s[0] == 'i') {
            ip.push_back(s);
        }
        else {
            bgp_area.insert({bg, are});
            area_ip.insert({ar, ip});
        }
    }
    string s2;
    while (s2 != "#") {
        getline(cin, s2);
        if (s2 == "#") break;
        unse.insert(s2);
    }

    //需要对bgp排序
    if (unse.count("bgp")) {
        vector<string> bgsort;
        for (auto& b : bgp_area) bgsort.push_back(b.first);
        sort(bgsort.begin(), bgsort.end(), less<string>());
        if (unse.count("area")) {
            for (auto& b : bgsort) {
                cout << b << endl;
                vector<string> arsort = bgp_area[b];
                sort(arsort.begin(), arsort.end(), less<string>());
                if (unse.count("ip route")) {
                    for (auto& a : arsort) {
                        cout << a << endl;
                        vector<string> ipsort = area_ip[a];
                        sort(ipsort.begin(), ipsort.end(), less<string>());
                        for (auto& r : ipsort) cout << r << endl;
                    }
                }
                else {
                    for (auto& a : arsort) {
                        cout << a << endl;
                        vector<string> ipsort = area_ip[a];
                        for (auto& r : ipsort) cout << r << endl;
                    }
                }
            }
        }
        else {
            for (auto& b : bgsort) {
                cout << b << endl;
                vector<string> arsort = bgp_area[b];
                if (unse.count("ip route")) {
                    for (auto& a : arsort) {
                        cout << a << endl;
                        vector<string> ipsort = area_ip[a];
                        sort(ipsort.begin(), ipsort.end(), less<string>());
                        for (auto& r : ipsort) cout << r << endl;
                    }
                }
                else {
                    for (auto& a : arsort) {
                        cout << a << endl;
                        vector<string> ipsort = area_ip[a];
                        for (auto& r : ipsort) cout << r << endl;
                    }
                }
            }
        }
    }
    else {
        vector<string> bgsort;
        for (auto& b : bgp_area) bgsort.push_back(b.first);
        if (unse.count("area")) {
            for (auto& b : bgsort) {
                cout << b << endl;
                vector<string> arsort = bgp_area[b];
                sort(arsort.begin(), arsort.end(), less<string>());
                if (unse.count("ip route")) {
                    for (auto& a : arsort) {
                        cout << a << endl;
                        vector<string> ipsort = area_ip[a];
                        sort(ipsort.begin(), ipsort.end(), less<string>());
                        for (auto& r : ipsort) cout << r << endl;
                    }
                }
                else {
                    for (auto& a : arsort) {
                        cout << a << endl;
                        vector<string> ipsort = area_ip[a];
                        for (auto& r : ipsort) cout << r << endl;
                    }
                }
            }
        }
        else {
            for (auto& b : bgsort) {
                cout << b << endl;
                vector<string> arsort = bgp_area[b];
                if (unse.count("ip route")) {
                    for (auto& a : arsort) {
                        cout << a << endl;
                        vector<string> ipsort = area_ip[a];
                        sort(ipsort.begin(), ipsort.end(), less<string>());
                        for (auto& r : ipsort) cout << r << endl;
                    }
                }
                else {
                    for (auto& a : arsort) {
                        cout << a << endl;
                        vector<string> ipsort = area_ip[a];
                        for (auto& r : ipsort) cout << r << endl;
                    }
                }
            }
        }
    }
    return 0;
}
/*
用例一：
bgp 300
area 3
ip route 3.1.1.1 32 10.0.0.1
ip route 3.1.1.2 32 10.0.0.1
ip route 3.1.1.3 32 10.0.0.1
bgp 1000
area 5
ip route 2.1.1.3 32 10.0.0.1
ip route 2.1.1.1 32 10.0.0.1
ip route 2.1.1.2 32 10.0.0.1
area 10
ip route 1.1.1.3 32 10.0.0.1
ip route 1.1.1.2 32 10.0.0.1
ip route 1.1.1.1 32 10.0.0.1
#
bgp
area
ip route
#

用例二：
bgp 300
area 3
ip route 3.1.1.1 32 10.0.0.1
ip route 3.1.1.2 32 10.0.0.1
ip route 3.1.1.3 32 10.0.0.1
bgp 1000
area 5
ip route 2.1.1.3 32 10.0.0.1
ip route 2.1.1.1 32 10.0.0.1
ip route 2.1.1.2 32 10.0.0.1
area 10
ip route 1.1.1.3 32 10.0.0.1
ip route 1.1.1.2 32 10.0.0.1
ip route 1.1.1.1 32 10.0.0.1
#
bgp
ip route
#
*/