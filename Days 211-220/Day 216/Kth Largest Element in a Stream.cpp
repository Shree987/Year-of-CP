/*
Author : Shreeraksha R Aithal
Problem name : Kth Largest Element in a Stream
Problem link : https://leetcode.com/problems/kth-largest-element-in-a-stream/
Difficulty : Easy
Tags : Binary Tree, Binary Search Tree, Design, Tree
*/

class KthLargest {
    priority_queue <int, vector<int>, greater<int>>  pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto &n : nums){
            pq.push(n);
        }
        while(pq.size() > K){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K)       pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */