/*
Author : Shreeraksha R Aithal
Problem name : Zigzag Conversion
Problem link : https://leetcode.com/problems/zigzag-conversion/
Difficulty : Medium
Tags : String
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)        return s;
        int i, n = s.size(), k = 0;
        string res(n, ' ');
        for(i = 0; i < n; i += 2*numRows - 2){
            res[k++] = s[i];
        }
        for(int j = 1; j < numRows-1; j++){
            for(i = j; i < n; i += 2*numRows - 2){
                res[k++] = s[i];
                if(i+2*(numRows-j-1) < n)     res[k++] = s[i+2*(numRows-j-1)];
            }
        }
        for(i = numRows-1; i < n; i += 2*numRows - 2){
            res[k++] = s[i];
        }
        return res;
    }
};