/*
Author : Shreeraksha R Aithal
Problem name : Minimum Numbers of Function Calls to Make Target Array
Problem link : https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/
Difficulty : Medium
Tags : Array, Greedy
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int plus = 0, mult = 0, cnt, temp;
        map<int, int> mp;
        for(auto num : nums){
            if(num == 0)    continue;
            if(mp[num] == 0){
                cnt = 0;
                temp = num;
                while(temp > 0){
                    if(temp % 2 == 0){
                        cnt++;
                        temp /= 2;
                    }
                    else{
                        temp--;
                        mp[num]++;
                    }
                }
                mult = max(mult, cnt);
            }
            plus += mp[num];
        }
        return plus + mult;
    }
};