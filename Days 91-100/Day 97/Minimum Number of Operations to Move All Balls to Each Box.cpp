/*
Author : Shreeraksha R Aithal
Problem name : Minimum Number of Operations to Move All Balls to Each Box
Problem link : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
Difficulty : Medium
Tags : Array, String
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), total_left = 0, total_right = 0;
        vector<int> ans(n, 0);
        for(int i = 1; i < n; i++){
            if(boxes[i] == '1'){
                ans[0] += i;
                total_right++;
            }
        }
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] - total_right;
            if(boxes[i] == '1')     total_right--;
            if(boxes[i-1] == '1')   total_left++;
            ans[i] += total_left;
        }
        return ans;
    }
};