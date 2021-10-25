/*
Author : Shreeraksha R Aithal
Problem name : Sliding Window Maximum
Problem link : https://leetcode.com/problems/sliding-window-maximum/
Difficulty : Hard
Tags : Array, Heap (Priority Queue), Monotonic Queue, Queue, Sliding Window
*/

#define pii pair<int,int>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)  return nums;
        priority_queue<pii> pq;
        int i, j = 0;
        for(i = 0; i < nums.size(); i++){
            while(!pq.empty() && i-k >= pq.top().second)      pq.pop();
            pq.push({nums[i], i});
            if(i >= k-1)   nums[j++] = pq.top().first;
        }
        nums.erase(nums.end()-k+1, nums.end());
        return nums;
    }
};