/*
Author : Shreeraksha R Aithal
Problem name : Two Sum II - Input Array Is Sorted
Problem link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Difficulty : Easy
Tags : Array, Binary Search, Two Pointers
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, -1);
        int left = 0, right = numbers.size()-1;
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                ans[0] = left+1;
                ans[1] = right+1;
                break;
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else    left++;
        }
        return ans;
    }
};