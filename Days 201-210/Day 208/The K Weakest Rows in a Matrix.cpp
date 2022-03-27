/*
Author : Shreeraksha R Aithal
Problem name : The K Weakest Rows in a Matrix
Problem link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
Difficulty : Easy
Tags : Array, Binary Search, Heap (Priority Queue), Matrix, Sorting
*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int i, j = 0, n = mat.size(), m = mat[0].size();
        vector<pair<int,int>> vp(n);
        for(i = 0; i < n; i++, j = 0){
            while(j<m && mat[i][j] == 1)   j++;                   
            vp[i] = {j, i};
        }
        sort(vp.begin(), vp.end());
        vector<int> answer(k);
        for(i = 0; i < k; i++){
            answer[i] = vp[i].second;
        }
        return answer;
    }
};