/*
Author : Shreeraksha R Aithal
Problem name : Find All Duplicates in an Array
Problem link : https://leetcode.com/problems/find-all-duplicates-in-an-array/
Difficulty : Medium
Tags : Array, Hash Table
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        int i, n = nums.size();
        for(i = 0; i < n; i++){
            if(nums[i] == i+1)      continue;
            else if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        for(i = 0; i < n; i++){
            if(nums[i] != i+1)      answer.push_back(nums[i]);
        }
        return answer;
    }
};