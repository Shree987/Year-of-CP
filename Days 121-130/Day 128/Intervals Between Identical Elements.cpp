/*
Author : Shreeraksha R Aithal
Problem name : Intervals Between Identical Elements
Problem link : https://leetcode.com/problems/intervals-between-identical-elements/
Difficulty : Medium
Tags : Array, Hash Table, Prefix Sum
*/

class Solution {
    void calculateVal(vector<long long>& v, vector<long long>& res){
        int n = v.size(), i, j;
        vector<long long> prefix(n, 0), suffix(n, 0);
        for(i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + v[i-1];
        }
        for(i = n-2; i >= 0; i--){
            suffix[i] = suffix[i+1] + v[i+1];
        }
        for(int i = 1; i < n-1; i++){
            res[v[i]] = v[i]*(2*i-n+1) - prefix[i] + suffix[i];
        }
        res[v[0]] = suffix[0] - v[0]*(n-1);
        res[v[n-1]] = -prefix[n-1] + v[n-1]*(n-1);
    }
public:
    vector<long long> getDistances(vector<int>& arr) {
        int i, n = arr.size(), m;
        vector<long long> res(n, 0L);
        unordered_map<int, vector<long long> > mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        for(auto p : mp){
            if(p.second.size() > 1)    calculateVal(p.second, res);
        }
        return res;
    }
};