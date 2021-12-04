/*
Author : Shreeraksha R Aithal
Problem name : Two Furthest Houses With Different Colors
Problem link : https://leetcode.com/problems/two-furthest-houses-with-different-colors/
Difficulty : Medium
Tags : Array, Greedy
*/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        for(int d = n-1; d >= 1; d--){
            for(int i = 0; i+d<n; i++){
                if(colors[i] != colors[i+d])    return d;
            }
        }
        return 0;
    }
};