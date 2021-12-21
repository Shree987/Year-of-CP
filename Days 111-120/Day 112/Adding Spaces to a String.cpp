/*
Author : Shreeraksha R Aithal
Problem name : Adding Spaces to a String 
Problem link : https://leetcode.com/problems/adding-spaces-to-a-string/
Difficulty : Medium
Tags : String
*/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size(), m = s.size(), i, j, k;
        if(n == 0)      return s;
        s.resize(n+m);
        j = n-1;
        i = m-1;
        k = m+n-1;
        while(i>=0){
            s[k] = s[i];
            if(j>=0 && i == spaces[j]){
                s[k-1] = ' ';
                k--;
                j--;
            }
            i--;
            k--;
        }
        return s;
    }
};