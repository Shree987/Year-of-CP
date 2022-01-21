/*
Author : Shreeraksha R Aithal
Problem name : Check if Every Row and Column Contains All Numbers
Problem link : https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
Difficulty : Easy
Tags : Array, Hash Table, Matrix
*/

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size(), i, j;
        vector<int> arr(n+1, 0);
        for(i = 0; i < n; i++){
            if(i%2 == 0){
                for(j = 0; j < n; j++){
                    if(arr[matrix[i][j]] == 1)      return false;
                    arr[matrix[i][j]] = 1;
                }
            }
            else{
                for(j = 0; j < n; j++){
                    if(arr[matrix[i][j]] == 0)      return false;
                    arr[matrix[i][j]] = 0;
                }
            }
        }
        arr[0] = arr[1];
        for(i = 0; i < n; i++){
            if(i%2 == 0){
                for(j = 0; j < n; j++){
                    if(arr[matrix[j][i]] == 1-arr[0])      return false;
                    arr[matrix[j][i]] = 1-arr[0];
                }
            }
            else{
                for(j = 0; j < n; j++){
                    if(arr[matrix[j][i]] == arr[0])      return false;
                    arr[matrix[j][i]] = arr[0];
                }
            }
        }
        return true;
    }
};