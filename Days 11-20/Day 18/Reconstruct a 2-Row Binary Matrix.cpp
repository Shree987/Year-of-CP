/*
Author : Shreeraksha R Aithal
Problem name : Reconstruct a 2-Row Binary Matrix
Problem link : https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
Difficulty : Medium
Tags : Array, Greedy, Matrix
*/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size(), ind;
        vector<vector<int>> mat(2, vector<int>(n, -1));
        for(ind = 0; ind < n; ind++){
            if(colsum[ind] == 0)    mat[0][ind] = mat[1][ind] = 0;
            else if(colsum[ind] == 2){
                mat[0][ind] = 1;
                mat[1][ind] = 1;
                upper--;
                lower--;
            }
        }
        for(ind = 0; ind < n; ind++){
            if(colsum[ind] == 1){
                if(upper>0){
                    mat[0][ind] = 1;
                    upper--;
                    mat[1][ind] = 0;
                }
                else{
                    lower--;
                    mat[0][ind] = 0;
                    mat[1][ind] = 1;
                }
            }
        }
        if(!(upper == 0 && lower == 0))      mat.clear();
        return mat;
    }
};