/*
Author : Shreeraksha R Aithal
Problem name : 
Problem link : https://leetcode.com/problems/contiguous-array/
Difficulty : Medium
Tags : Array, Hash Table, Prefix Sum
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            count += (nums[i-1] == 0 ? -1 : 1);
            if(mp.find(count) == mp.end())      mp[count] = i;
            else{
                res = max(res, i - mp[count]);
            }
        }
        return res;
    }
};