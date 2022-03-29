/*
Author : Shreeraksha R Aithal
Problem name : Find the Duplicate Number
Problem link : https://leetcode.com/problems/find-the-duplicate-number/
Difficulty : Medium
Tags : Array, Binary Search, Bit Manipulation, Two Pointers
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size()-1;
        while(left < right){
            int cnt1 = 0, cnt2 = 0, mid = left + (right-left)/2;
            for(auto &val : nums){
                if(left <= val && val <= mid)       cnt1++;
                if(mid < val && val <= right)       cnt2++;
            }
            if(mid-left+1 < cnt1)       right = mid;
            else        left = mid+1;
        }
        return left;        
    }
};