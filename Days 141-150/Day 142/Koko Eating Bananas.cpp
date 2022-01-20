/*
Author : Shreeraksha R Aithal
Problem name : Koko Eating Bananas
Problem link : https://leetcode.com/problems/koko-eating-bananas/
Difficulty : Medium
Tags : Array, Binary Search
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long low = 1, high = *max_element(piles.begin(), piles.end()), i, n = piles.size();
        while(low < high){
            long mid = low + (high-low)/2;
            long H = h;
            for(i = 0; H>0 && i < n; i++){
                H -= (piles[i]+mid-1)/mid;
            }
            if(i == n && H>=0){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};