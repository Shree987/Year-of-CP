/*
Author : Shreeraksha R Aithal
Problem name : Minimize Deviation in Array
Problem link : https://leetcode.com/problems/minimize-deviation-in-array/
Difficulty : Hard
Tags : Array, Greedy, Heap(Priority Queue), OrderedSet
*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int diff, Min = INT_MAX, Max = INT_MIN;
        priority_queue<int> pq;
        for(auto &k : nums){
            if(k%2 == 1)     k*=2;
            pq.push(k);
            Min = min(Min, k);
            Max = max(Max, k);
        }
        diff = Max - Min;
        while((pq.top()%2) == 0){
            int k = pq.top();
            pq.pop();
            diff = min(diff, k - Min);
            k /= 2;
            Min = min(Min, k);
            pq.push(k);
        }
        diff = min(diff, pq.top() - Min);
        return diff;
    }
};