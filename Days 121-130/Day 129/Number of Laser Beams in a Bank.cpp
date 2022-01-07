/*
Author : Shreeraksha R Aithal
Problem name : Number of Laser Beams in a Bank
Problem link : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
Difficulty : Medium
Tags : Array, Math, Matrix, String
*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, total = 0;
        for(int i = 0; i < bank.size(); i++){
            int cnt = 0;
            for(int j = 0; j < bank[i].size(); j++){
                cnt += (bank[i][j] - '0');
            }
            if(prev == 0)   prev = cnt;
            else{
                if(cnt > 0){
                    total += prev*cnt;
                    prev = cnt;
                }
            }
        }
        return total;
    }
};