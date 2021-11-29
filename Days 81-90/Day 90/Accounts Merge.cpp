/*
Author : Shreeraksha R Aithal
Problem name : Accounts Merge
Problem link : https://leetcode.com/problems/accounts-merge/
Difficulty : Medium
Tags : Array, Breadth-first Search, Depth-first Search, String, Union Find
*/

class Solution {
    int findParent(vector<int>& parent, int p){
        if(parent[p] == p)      return p;
        return parent[p] = findParent(parent, parent[p]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int i, j, p1, p2, n = accounts.size();
        vector<int> parent(n, -1), index(n, -1);
        map<string, int> mp;
        for(i = 0; i < n; i++){
            parent[i] = i;
            for(j = 1; j < accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = parent[i];
                }
                else{
                    p1 = findParent(parent, i);
                    p2 = findParent(parent, mp[accounts[i][j]]);
                    if(p2 < p1)     swap(p1, p2);
                    parent[p2] = p1;
                }
            }
        }
        vector<vector<string>> ans;
        for(i = 0, j = 0; i < n; i++){
            parent[i] = findParent(parent, i);
            if(i == parent[i]){
                index[i] = j;
                ans.push_back({accounts[i][0]});
                j++;
            }
        }
        for(auto m : mp){
            ans[index[parent[m.second]]].push_back(m.first);            
        }
        return ans;
    }
};