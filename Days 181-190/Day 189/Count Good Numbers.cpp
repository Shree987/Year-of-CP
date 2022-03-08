/*
Author : Shreeraksha R Aithal
Problem name : Count Good Numbers
Problem link : https://leetcode.com/problems/count-good-numbers/
Difficulty : Medium
Tags : Math, Recursion
*/

#define MAX 1000000007
class Solution {
    long long modPow(long long n, long long pow){
        if(pow == 0)    return 1;
        else if(pow == 1)       return n;
        long long ans = modPow(n, pow/2);
        ans = (ans * ans)%MAX;
        if(pow%2 == 1)    ans = (ans * n)%MAX;
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        return (modPow(5, (n+1)/2) * modPow(4, n/2))%MAX;
    }
};