/*
Author : Shreeraksha R Aithal
Problem name : Most Visited Sector in a Circular Track
Problem link : https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
Difficulty : Easy
Tags : Array, Simulation
*/

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int m = rounds.size();
        if(rounds[m-1] == rounds[0]){
            return vector<int>(1, rounds[0]);
        }
        else if(rounds[m-1] > rounds[0]){
            vector<int> v(rounds[m-1] - rounds[0] + 1, rounds[0]);
            for(int i = 0; i <= rounds[m-1] - rounds[0]; i++){
                v[i] += i;
            }
            return v;
        }
        else{
            vector<int> v(rounds[m-1] + n - rounds[0] + 1, rounds[0]);
            for(int i = 1; i <= rounds[m-1]; i++){
                v[i - 1] = i;
            }
            for(int i = 0; i <= n-rounds[0]; i++){
                v[rounds[m-1] + i] = rounds[0] + i;
            }
            return v;
        }
        return vector<int>();
    }
};