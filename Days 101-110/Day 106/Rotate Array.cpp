/*
Author : Shreeraksha R Aithal
Problem name : Rotate Array
Problem link : https://leetcode.com/problems/rotate-array/
Difficulty : Medium
Tags : Array, Math, Two Pointer
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(k == 0)      return ;
        int i, n = nums.size(), j, x, gcd = __gcd(n, k);
        for(i = 0; i < gcd; i++){
            j = i;
            x = nums[j];
            do{
                swap(x, nums[(j+k)%n]);
                j = (j+k)%n;
            }while(j != i);
        }
    }
};