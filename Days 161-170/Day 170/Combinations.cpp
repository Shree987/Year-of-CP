/*
Author : Shreeraksha R Aithal
Problem name : Combinations
Problem link : https://leetcode.com/problems/combinations/
Difficulty : Medium
Tags : Array, Backtracking
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vp, v;
        if(n < k)   return vp;
        for(int i = 1; i <=n ; i++){
            vp.push_back({i});
        }
        while(k > 1){
            for(auto &vec : vp){
                int num = vec[vec.size()-1]+1;
                for(; num <= n; num++){
                    vec.push_back(num);
                    v.push_back(vec);
                    vec.pop_back();
                }
            }
            vp.swap(v);
            v.clear();
            k--;
        }
        return vp;
    }
};