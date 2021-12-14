/*
Author : Shreeraksha R Aithal
Problem name : Rings and Rods
Problem link : https://leetcode.com/problems/rings-and-rods/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    int countPoints(string rings) {
        vector<int> arr(10, 0);
        int n = rings.size();
        for(int i = 0; i < rings.size(); i+=2){
            if(rings[i] == 'R')     arr[rings[i+1]-'0'] = arr[rings[i+1]-'0'] | 1;
            else if(rings[i] == 'G')     arr[rings[i+1]-'0'] = arr[rings[i+1]-'0'] | 2;
            else if(rings[i] == 'B')     arr[rings[i+1]-'0'] = arr[rings[i+1]-'0'] | 4;
        }
        n = 0;
        for(int i = 0; i < 10; i++){
            n += arr[i]/7;
        }
        return n;
    }
};