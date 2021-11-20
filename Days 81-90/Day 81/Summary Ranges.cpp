/*
Author : Shreeraksha R Aithal
Problem name : Summary Ranges
Problem link : https://leetcode.com/problems/summary-ranges/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0, end;
        vector<string> ans;
        if(nums.empty())    return ans;
        for(end = 1; end < nums.size(); end++){
            if(nums[end] == nums[end-1]+1)      continue;
            else{
                if(end == start+1)      ans.push_back(to_string(nums[start]));
                else    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end-1]));
                start = end;
            }
        }
        if(end == start+1)      ans.push_back(to_string(nums[start]));
        else    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end-1]));
        return ans;
    }
};