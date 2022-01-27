/*
Author : Shreeraksha R Aithal
Problem name : Rearrange Array Elements by Sign
Problem link : https://leetcode.com/problems/rearrange-array-elements-by-sign/
Difficulty : Medium
Tags : Array, Simulation, Two Pointers
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0, k = 0;
        queue<int> pos, neg;
        while(k < nums.size()){
            if(nums[k] > 0)     pos.push(nums[k]);
            else                neg.push(nums[k]);
            k++;
        }
        k = 0;
        while(!pos.empty()){
            nums[k++] = pos.front();
            pos.pop();
            nums[k++] = neg.front();
            neg.pop();
        }
        return nums;
    }
};