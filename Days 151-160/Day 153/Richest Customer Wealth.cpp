/*
Author : Shreeraksha R Aithal
Problem name : Richest Customer Wealth
Problem link : https://leetcode.com/problems/richest-customer-wealth/
Difficulty : Easy
Tags : Array, Matrix
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int index = 0;
        for(int j, i = 0; i < accounts.size(); i++){
            for(j = 1; j < accounts[i].size(); j++){
                accounts[i][0] += accounts[i][j];
            }
            if(accounts[i][0] > accounts[index][0])     index = i;
        }
        return accounts[index][0];
    }
};