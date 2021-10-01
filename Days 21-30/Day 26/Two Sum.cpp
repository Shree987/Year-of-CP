/*
Author : Shreeraksha R Aithal
Problem name : Two Sum
Problem link : https://leetcode.com/problems/two-sum/ 
Difficulty : Easy
Tags : Array, Hash Table
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<pair<int, int>> vp(nums.size());
        for(int i = 0; i < nums.size(); i++){
            vp[i] = {nums[i], i};
        }
        sort(vp.begin(), vp.end());
        int left = 0, right = nums.size()-1;
        while(left < right){
            if(vp[left].first + vp[right].first == target){
                res = {vp[left].second, vp[right].second};
                break;
            }
            else if(vp[left].first + vp[right].first > target){
                right--;
            }
            else    left++;
        }
        return res;
    }
};