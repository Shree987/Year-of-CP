/*
Author : Shreeraksha R Aithal
Problem name : Jump Game
Problem link : https://leetcode.com/problems/jump-game/
Difficulty : Medium
Tags : Array, Dynamic Programming, Greedy
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, j, n = nums.size();
        vector<bool> res(n, false);
        res[n-1] = true;
        for(i = n-2; i >=0; i--){
            for(j = i+1; j <n && j<=i+nums[i]; j++){
                if(res[j]){
                    res[i] = true;
                    break;
                }
            }
        }
        return res[0];
    }
};