/*
Author : Shreeraksha R Aithal
Problem name : Compare Version Numbers
Problem link : https://leetcode.com/problems/compare-version-numbers/
Difficulty : Medium
Tags : String, Two Pointers
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int val1, val2, i = 0, j = 0, n = version1.size(), m = version2.size();
        while(i < n || j < m){
            val1 = 0;
            if(i < n){
                val1 = 0;
                while(i < n && version1[i] != '.'){
                    val1 = val1*10 + (version1[i]-'0');
                    i++;
                }
                i++;
            }            
            val2 = 0;
            if(j < m){
                val2 = 0;
                while(j < m && version2[j] != '.'){
                    val2 = val2*10 + (version2[j]-'0');
                    j++;
                }
                j++;
            }
            if(val1 < val2) return -1;
            if(val1 > val2) return 1;
        }
        return 0;
    }
};