/*
Author : Shreeraksha R Aithal
Problem name : Friends Of Appropriate Ages
Problem link : https://leetcode.com/problems/friends-of-appropriate-ages/
Difficulty : Medium
Tags : Array, Binary Search, Sorting, Two Pointers
*/

#define f first
#define s second
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int i = 0, j, n = ages.size(), m = 0, cnt = 0, k;
        vector<pair<int, int>> vp;
        sort(ages.begin(), ages.end());
        while(i < n){
            j = i+1;
            while(j<n && ages[i] == ages[j])    j++;
            for(k = 0; k < m; k++){
                if(2*vp[k].f > ages[i] + 14)      cnt += (j-i)*vp[k].s;
            }
            if(ages[i] > 14)       cnt += (j-i) * (j-i-1);
            vp.push_back({ages[i], j-i});
            m++;
            i = j;
        }
        return cnt;
    }
};