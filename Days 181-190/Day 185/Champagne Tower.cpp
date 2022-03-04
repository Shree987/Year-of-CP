/*
Author : Shreeraksha R Aithal
Problem name : Champagne Tower
Problem link : https://leetcode.com/problems/champagne-tower/
Difficulty : Medium
Tags : Dynamic Programming
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        map<pair<int,int>, double> mp;
        mp[{0, 0}] = poured;
        bool end;
        for(int j, i = 0; i <= query_row; i++){
            end = true;
            mp[{i+1, 0}] = 0;
            for(j = 0; j <= i; j++){
                if(mp[{i, j}] > 1){
                    end = false;
                    double extra = mp[{i, j}]-1;
                    mp[{i, j}] = 1;
                    mp[{i+1, j}] += extra/2;                    
                    mp[{i+1, j+1}] = extra/2;
                }
                if(i == query_row && j == query_glass)      break;
            }
            if(end || j <= i)   break;
        }
        return mp[{query_row, query_glass}];
    }
};