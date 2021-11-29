/*
Author : Shreeraksha R Aithal
Problem name : Minimum Number of Buckets Required to Collect Rainwater from Houses
Problem link : https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
Difficulty : Medium
Tags : String
*/

class Solution {
public:
    int minimumBuckets(string street) {
        int count = 0, n = street.size();
        for(int i = 0; i < n; i++){
            if(street[i] == 'H'){
                if(i+1<n && street[i+1]=='.'){
                    count++;
                    i = i+2;
                }
                else if(i-1>=0 && street[i-1]=='.'){
                    count++;
                }
                else{
                    return -1;
                }
            }
        }
        return count;
    }
};