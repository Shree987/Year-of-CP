/*
Author : Shreeraksha R Aithal
Problem name : Top K Frequent Elements
Problem link : https://leetcode.com/problems/top-k-frequent-elements/
Difficulty : Medium
Tags : Array, Bucket Sort, Counting, Divide and Conquer, Hash Table, Heap (Priority Queue), Quicksort, Sorting
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, set<int> > mp;
        map<int, int> freq;
        for(auto n : nums){
            freq[n]++;
            mp[-freq[n]+1].erase(n);
            mp[-freq[n]].insert(n);
        }
        nums.resize(k);
        for(auto itr : mp){
            if(k == 0)      break;
            for(auto p : itr.second){
                nums[--k] = p;
            }
        }
        return nums;
    }
};