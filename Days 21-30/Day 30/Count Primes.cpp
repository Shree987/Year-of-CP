/*
Author : Shreeraksha R Aithal
Problem name : Count Primes
Problem link : https://leetcode.com/problems/count-primes/
Difficulty : Medium
Tags : Array, Enumeration, Math, Number Theory
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1)      return 0;
        if(n <= 3)      return n-2;
        vector<bool> arr(n+2, true);
        int i, j, cnt = 0;
        for(i = 2; i < n; i++){
            if(!arr[i])     continue;
            else{
                cnt++;
                for(j = i+i; j < n; j+=i){
                    arr[j] = false;
                }
            }
        }
        return cnt;
    }
};