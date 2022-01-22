/*
Author : Shreeraksha R Aithal
Problem name : Stone Game IV
Problem link : https://leetcode.com/problems/stone-game-iv/
Difficulty : Hard
Tags : Dynamic Programming, Game Theory, Math
*/

class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n <= 3){
            return (n%2 == 1);
        }
        int m = 1, itr;
        vector<int> sq;
        while(m*m < n){
            sq.push_back(m*m);
            m++;
        }
        if(m*m == n)    return true;
        vector<bool> arr(n+1, false);
        arr[1] = true;
        for(itr = 2; itr<=n; itr++){
            m = 0;
            while(m<sq.size() && sq[m]<=itr){
                if(arr[itr - sq[m]] == false){
                    arr[itr] = true;
                    break;
                }
                m++;
            }
        }
        return arr[n];
    }
};