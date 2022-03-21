// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem127.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 1;
        bool flag = false;
        queue<string> qu;
        qu.push(beginWord);
        while (!qu.empty() && !flag) {
            int qu_size = qu.size();
            for (int i = 0; i < qu.size(); ++i) {
                string temp = qu.front();
                qu.pop();
                if (temp == endWord) {
                    flag = true;
                    break;
                }
                for (int j = 0; j < wordList.size(); ++j) {
                    int t = 0;
                    for (int k = 0; k < wordList[j].size(); ++k) {
                        if (wordList[j][k] != temp[k]) t++;
                    }
                    if (t == 1) qu.push(wordList[j]);
                }
            }
            res++;
        }
        return res;
    }
};
// @lc code=end

