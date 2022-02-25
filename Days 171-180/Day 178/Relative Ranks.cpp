/*
Author : Shreeraksha R Aithal
Problem name : Relative Ranks
Problem link : https://leetcode.com/problems/relative-ranks/
Difficulty : Easy
Tags : Array, Heap (Prioirty Queue), Sorting
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> vp(score.size());
        for(int i = 0; i < score.size(); i++){
            vp[i] = {score[i], i};
        }
        sort(vp.rbegin(), vp.rend());
        vector<string> ans(score.size());
        ans[vp[0].second] = "Gold Medal";
        if(score.size() >= 2)   ans[vp[1].second] = "Silver Medal";
        if(score.size() >= 3)   ans[vp[2].second] = "Bronze Medal";
        for(int i = 3; i < score.size(); i++){
            ans[vp[i].second] = to_string(i+1);
        }
        return ans;
    }
};