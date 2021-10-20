/*
Author : Shreeraksha R Aithal
Problem name : Car Pooling
Problem link : https://leetcode.com/problems/car-pooling/
Difficulty : Medium
Tags : Array, Heap (Priority Queue), Prefix Sum, Simulation, Sorting
*/

#define pii pair<int,int>
bool compare2(vector<int>& a, vector<int>& b){
    if(a[1] != b[1])    return a[1]<=b[1];
    return a[2]<b[2];
}
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        sort(trips.begin(), trips.end(), compare2);
        int count = 0;
        for(auto p : trips){
            while(!pq.empty() && pq.top().first <= p[1]){
                count -= pq.top().second;
                pq.pop();
            }
            count += p[0];
            pq.push({p[2], p[0]});
            if(count > capacity)    return false;
        }
        return true;
    }
};