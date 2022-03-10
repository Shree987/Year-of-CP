/*
Author : Shreeraksha R Aithal
Problem name : Minimum Time to Complete Trips
Problem link : https://leetcode.com/problems/minimum-time-to-complete-trips/
Difficulty : Medium
Tags : Array, Binary Search
*/

#define ll long long
class Solution {
    void count(ll &T, vector<int>& time, ll &ans){
        ans = 0;
        for(auto &t : time){
            ans += T/t;
        }
    }
public:
    ll minimumTime(vector<int>& time, int totalTrips) {
        ll ans = 0, low = *min_element(time.begin(), time.end()), high = totalTrips, T;
        high = high * low;
        while(low < high){
            T = low + (high-low)/2;
            count(T, time, ans);
            if(ans < totalTrips){
                low = T+1;
            }
            else{
                high = T;
            }
        }
        return low;
    }
};