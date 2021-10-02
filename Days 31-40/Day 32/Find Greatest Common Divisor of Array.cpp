/*
Author : Shreeraksha R Aithal
Problem name : Find Greatest Common Divisor of Array
Problem link : https://leetcode.com/problems/find-greatest-common-divisor-of-array/
Difficulty : Easy
Tags : Array, Math
*/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int Min = nums[0], Max = nums[0];
        for(auto k : nums){
            if(k > Max)     Max = k;
            else if(k < Min)    Min = k;
        }
        return __gcd(Min, Max);
    }
};