/*
Author : Shreeraksha R Aithal
Problem name : Maximum Erasure Value
Problem link : https://leetcode.com/problems/maximum-erasure-value/
Difficulty : Medium
Tags : Array, Hash Table, Sliding Window
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {        
        long answer = nums[0], len = nums.size(), itr, start, end, sum = nums[0];
        if(len == 1)  return nums[0];
        vector<long> index(10004, -1);
        start = 0;
        end = 1;
        index[nums[0]] = 0;
        while(end < len){
            if(index[nums[end]] == -1){
                index[nums[end]] = end;
                sum += nums[end];
                answer = max(answer, sum);
            }
            else{
                for(int itr2 = start; itr2 < index[nums[end]]; itr2++){
                    sum -= nums[itr2];
                    index[nums[itr2]] = -1;
                }                
                start = index[nums[end]]+1;
                index[nums[end]] = end;
                answer = max(answer, sum);
            }
            end++;
        }
        return answer;
    }
};