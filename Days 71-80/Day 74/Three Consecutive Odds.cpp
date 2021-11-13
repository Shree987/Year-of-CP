/*
Author : Shreeraksha R Aithal
Problem name : Three Consecutive Odds
Problem link : https://leetcode.com/problems/three-consecutive-odds/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 0; i+2 < arr.size(); i++){
            if(arr[i+2]%2 == 0){
                i += 2;
                continue;
            }
            if(arr[i+1]%2 == 0){
                i++;
                continue;
            }
            if(arr[i]%2 == 0)   continue;
            return true;
        }
        return false;
    }
};