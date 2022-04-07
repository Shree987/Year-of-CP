/*
Author : Shreeraksha R Aithal
Problem name : Last Stone Weight
Problem link : https://leetcode.com/problems/last-stone-weight/
Difficulty : Easy
Tags : Array, Heap (Priority Queue)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &num : stones){
            pq.push(num);
        }
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(y != x){
                pq.push(abs(y-x));
            }
        }
        pq.push(0);
        return pq.top();
    }
};