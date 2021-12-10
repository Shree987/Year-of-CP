/*
Author : Shreeraksha R Aithal
Problem name : Decompress Run-Length Encoded List
Problem link : https://leetcode.com/problems/decompress-run-length-encoded-list/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int> array;
        for(int i = 0; i < n; i+=2){
            vector<int> a(nums[i], nums[i+1]);
            array.insert(array.end(), a.begin(), a.end());
        }
        return array;
    }
};