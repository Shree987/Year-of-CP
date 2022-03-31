/*
Author : Shreeraksha R Aithal
Problem name : Convert 1D Array Into 2D Array
Problem link : https://leetcode.com/problems/convert-1d-array-into-2d-array/
Difficulty : Easy
Tags : Array, Matrix, Simulation
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> vec(m, vector<int>(n));
        if(m*n != original.size()){
            vec.clear();
            return vec;
        }
        int k = 0;
        for(int j, i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                vec[i][j] = original[k++];
            }
        }
        return vec;
    }
};