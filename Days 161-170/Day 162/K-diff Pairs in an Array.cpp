/*
Author : Shreeraksha R Aithal
Problem name : K-diff Pairs in an Array
Problem link : https://leetcode.com/problems/k-diff-pairs-in-an-array/
Difficulty : Medium
Tags : Array, Binary Search, Hash Table, Sorting, Two Pointers
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0, Max = nums[0];
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            Max = max(Max, nums[i]);
            mp[nums[i]]++;
        }
        for(auto &p : mp){
            if(k == 0 && p.second>1)    cnt++;
            else if(k>0 && mp.find(p.first+k) != mp.end()){
                cnt++;
            }
        }
        return cnt;
    }
};