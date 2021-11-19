/*
Author : Shreeraksha R Aithal
Problem name : Total Hamming Distance
Problem link : https://leetcode.com/problems/total-hamming-distance/
Difficulty : Medium
Tags : Array, Bit Manipulation, Math
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt, sum = 0, n = nums.size();
        for(int j, i = 32; i > 0; i--){
            cnt = 0;
            for(j = 0; j < n; j++){
                if(nums[j]%2 == 1)  cnt++;
                nums[j] /= 2;
            }
            sum += cnt*(n-cnt);
        }
        return sum;
    }
};