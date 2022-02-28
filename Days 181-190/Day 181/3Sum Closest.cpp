/*
Author : Shreeraksha R Aithal
Problem name : 3Sum Closest
Problem link : https://leetcode.com/problems/3sum-closest/
Difficulty : Medium
Tags : Array, Sorting, Two Pointers
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int answer = nums[0] + nums[1] + nums[2];
        for(int i = 0; answer != target && i < nums.size(); i++){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(answer - target) > abs(target - sum)){
                    answer = sum;
                }
                if(sum > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return answer;
    }
};