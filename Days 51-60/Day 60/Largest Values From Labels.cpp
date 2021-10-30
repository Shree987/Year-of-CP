/*
Author : Shreeraksha R Aithal
Problem name : Largest Values From Labels
Problem link : https://leetcode.com/problems/largest-values-from-labels/
Difficulty : Medium
Tags : Array, Counting, Greedy, Hash Table, Sorting
*/

#define pii pair<int,int>
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int cnt = 0;
        unordered_map<int,int> mp;
        priority_queue<pii> pq;
        for(int i = 0; i < values.size(); i++){
            pq.push({values[i], labels[i]});
        }
        while(numWanted > 0 && !pq.empty()){
            if(mp[pq.top().second] < useLimit){
                mp[pq.top().second]++;
                cnt += pq.top().first;
                numWanted--;
            }
            pq.pop();
        }
        return cnt;
    }
};