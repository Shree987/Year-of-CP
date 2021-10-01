/*
Author : Shreeraksha R Aithal
Problem name : Decrease Elements To Make Array Zigzag
Problem link : https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
Difficulty : Medium
Tags : Array, Greedy
*/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int even = 0, odd = 0, index, diff;
        for(index = 0; index < nums.size(); index++){
            diff = nums[index];
            if(index-1>=0)      diff = min(diff, nums[index-1]-1);
            if(index+1<nums.size())      diff = min(diff, nums[index+1]-1);
            if(index%2 == 0){
                even += nums[index]-diff;
            }
            else{
                odd += nums[index]-diff;
            }
        }
        return min(odd, even);
    }
};