#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode{
    bool isEnd;
    unordered_map<char, TrieNode*> child;
    TrieNode() : isEnd(false) {};
};

class Trie{
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            if (node->child.count(c) == 0) {
                node->child[c] = new TrieNode();
            }
            node = node->child[c];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            if (node->child.count(c) == 0) return false;
            node = node->child[c];
        }
        return node->isEnd == true;
    }

    vector<string> res;
    void traverse(TrieNode* node, string s) {
        if (node->isEnd) {
            res.push_back(s);
            return ;
        }
        for (auto c : node->child) {
            s.push_back(c.first);
            traverse(c.second, s);
            s.pop_back();
        }
    }

    vector<string> findAllString(string prefix) {
        TrieNode* node = root;
        string s = "";
        for (auto c : prefix) {
            if (node->child.count(c) == 0) break;
            node = node->child[c];
            s.push_back(c);
        }
        traverse(node, s);
        return res;
    }
};

int main() {
    Trie a;
    string word1 = "17829114860";
    a.insert(word1);
    string word2 = "17850062267";
    a.insert(word2);
    string word3 = "17349177416";
    a.insert(word3);
    cout << a.search("17829114860") << endl;
    vector<string> res = a.findAllString("17");
    for (auto r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}