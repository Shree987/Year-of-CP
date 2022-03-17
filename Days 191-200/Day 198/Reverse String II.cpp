/*
Author : Shreeraksha R Aithal
Problem name : Reverse String II
Problem link : https://leetcode.com/problems/reverse-string-ii/
Difficulty : Easy
Tags : String, Two Pointers
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        if(k == 1)      return s;
        int i, j, n = s.size(), m;
        for(m = 0; m < n; m+=2*k){
            i = m;
            j = min(n-1, m+k-1);
            while(i < j){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};