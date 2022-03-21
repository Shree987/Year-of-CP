/*
Author : Shreeraksha R Aithal
Problem name : Partition Labels
Problem link : https://leetcode.com/problems/partition-labels/
Difficulty : Medium
Tags : Greedy, Hash Table, String, Two Pointers
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res, freq(26, 0);
        int start = 0, end, ind;
        for(ind = 0; ind < s.size(); ind++){
            freq[s[ind]-'a'] = ind;
        }
        while(start < s.size()){
            ind = start;
            end = freq[s[start]-'a'];
            while(ind < end){
                ind++;
                end = max(end, freq[s[ind]-'a']);
            }
            res.push_back(end-start+1);
            start = end+1;
        }
        return res;
    }
};