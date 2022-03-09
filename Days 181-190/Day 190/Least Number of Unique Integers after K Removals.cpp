/*
Author : Shreeraksha R Aithal
Problem name : Least Number of Unique Integers after K Removals
Problem link : https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
Difficulty : Medium
Tags : Array, Counting, Greedy, Hash Table, Sorting
*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<int> nums;
        int index;
        unordered_map<int,int> mp;
        for(auto &m : arr){
            if(mp.find(m) == mp.end()){
                mp[m] = nums.size();
                nums.push_back(1);
            }
            else{
                nums[mp[m]]++;
            }
        }
        mp.clear();
        sort(nums.begin(), nums.end());
        for(index = 0; index < nums.size() && k>=nums[index]; index++){
            k -= nums[index];
        }
        return nums.size() - index;
    }
};