/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
public:
    //采用回溯的方法
    vector<string> res;
    string tem = "JFK";
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        res.push_back("JFK");
        backtracking(tickets, 0);
        return res;
    }
    void backtracking(vector<vector<string>>& tickets,int pos){
        if(){
            res.push_back();
        }
        for(int i=pos;i<tickets.size();++i){
            if(tickets[i][0]==tem){
                tem = tickets[i][0];
                backtracking(tickets, i+1);
            }
        }
    }
};
// @lc code=end

