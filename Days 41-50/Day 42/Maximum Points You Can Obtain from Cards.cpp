/*
Author : Shreeraksha R Aithal
Problem name : Maximum Points You Can Obtain from Cards
Problem link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
Difficulty : Medium
Tags : Array, Prefix Sum, Sliding Window
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i, j, sum = 0, cnt = 0;
        for(i = 0; i < k; i++)  sum += cardPoints[i];
        cnt = sum;
        for(i = k-1, j = cardPoints.size()-1; i>=0; i--, j--){
            cnt += cardPoints[j]-cardPoints[i];
            sum = max(sum, cnt);
        }
        return sum;
    }
};