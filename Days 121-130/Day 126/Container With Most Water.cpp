/*
Author : Shreeraksha R Aithal
Problem name : Container With Most Water
Problem link : https://leetcode.com/problems/container-with-most-water/
Difficulty : Medium
Tags : Array, Greedy, Two Pointers
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, ans = 0;
        while(left < right){
            ans = max(ans, (right-left)*(min(height[left], height[right])));
            if(height[right] <= height[left])   right--;
            else    left++;
        }
        return ans;
    }
};