/*
Author : Shreeraksha R Aithal
Problem name : Number of Substrings Containing All Three Characters
Problem link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
Difficulty : Medium
Tags : Hash Table, Sliding Window, String
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0, sum = 0, i, j = -1, n = s.size();
        for(i = 0; i < n; i++){
            while(j<n && (a == 0 || b == 0 || c == 0)){
                j++;
                if(s[j] == 'a')     a++;
                else if(s[j] == 'b')    b++;
                else    c++;
            }
            if(a>0 && b>0 && c>0){
                sum += n-j;
            }
            if(s[i] == 'a')     a--;
            else if(s[i] == 'b')    b--;
            else    c--;
        }
        return sum;
    }
};