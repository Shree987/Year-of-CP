/*
Author : Shreeraksha R Aithal
Problem name : Nth Magical Number
Problem link : https://leetcode.com/problems/nth-magical-number/
Difficulty : Hard
Tags : Binary Search, Math
*/

#define m 1000000007
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        if(b < a)   min(a, b);
        if(b%a == 0){
            return (((long) a)*n)%m;
        }
        long sum, gcd = __gcd(a, b), total = 0, A, B;
        sum = a/gcd + b/gcd - 1;
        if(n%sum == 0)      return ((n/sum)*((b/gcd)*a))%m;
        else{
            total = ((n/sum)*((b/gcd)*a))%m;
            n %= sum;
            A = B = sum = 0;
            while(n>0){
                if(A + a < B + b){
                    A += a;
                    sum = A;
                }
                else{
                    B += b;
                    sum = B;
                }
                n--;
            }
        }
        return (total%m + sum%m)%m;
    }
};