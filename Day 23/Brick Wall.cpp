/*
Author : Shreeraksha R Aithal
Problem name : Brick Wall
Problem link : https://leetcode.com/problems/brick-wall/
Difficulty : Medium
Tags : Array, Hash Table
*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int sum = 0, cnt = 0, S = 0;
        for(auto k : wall[0]){
            S += k;
        }
        map<int, int> mp;
        for(auto v : wall){
            sum = 0;
            for(auto k : v){
                sum += k;
                mp[sum]++;
                if(S!=sum && mp[sum] > cnt){
                    cnt = mp[sum];
                }
            }
        }
        return wall.size()-cnt;
    }
};