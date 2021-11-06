/*
Author : Shreeraksha R Aithal
Problem name : 
Problem link : https://leetcode.com/problems/single-number-iii/
Difficulty : Medium
Tags : Array, Bit Manipulation
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) == st.end())    st.insert(nums[i]);
            else    st.erase(nums[i]);
        }
        int i = 0;
        nums.resize(2);
        for(auto m : st){
            nums[i++] = m;
        }
        return nums;
    }
};