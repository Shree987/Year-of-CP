/*
Author : Shreeraksha R Aithal
Problem name : Assign Cookies
Problem link : https://leetcode.com/problems/assign-cookies/
Difficulty : Easy
Tags : Array, Greedy, Sorting
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int i = g.size()-1, j = s.size()-1;
        while(i>=0 && j>=0){
            if(g[i]<=s[j])  i--;
            j--;
        }
        return g.size()-i-1;
    }
};