/*
Author : Shreeraksha R Aithal
Problem name : Longest Substring Without Repeating Characters
Problem link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
Difficulty : Medium
Tags : Hash Table, Sliding Window, String
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[258], start = -1, ind, answer = 0;
        memset(arr, -1, sizeof(arr));
        for(ind = 0; ind < s.size(); ind++){
            start = max(start, arr[s[ind]]);
            arr[s[ind]] = ind;
            answer = max(answer, ind-start);
        }
        return answer;
    }
};