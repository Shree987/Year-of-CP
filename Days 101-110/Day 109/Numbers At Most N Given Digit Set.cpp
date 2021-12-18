/*
Author : Shreeraksha R Aithal
Problem name : Numbers At Most N Given Digit Set
Problem link : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
Difficulty : Hard
Tags : Array, Binary Search, Dynamic Programming, Math
*/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        long k = digits.size(), count = 0, m = to_string(n).size(), curr, cnt = 0;
        for(int i = 1; i < m; i++){
            count += pow(k, i);
        }
        vector<int> dp(10, 0);
        for(int i = 0, j = 1; j < 10; j++){
            if(i < k && (digits[i][0]-'0') == j){
                dp[j] = dp[j-1]+1;
                i++;
            }
            else    dp[j] = dp[j-1];
        }
        curr = dp[n%10];
        n = n/10;
        cnt = 1;
        while(n > 0){
            if(dp[n%10] == 0){
                curr = 0;
            }
            else{
                curr = (dp[n%10 - 1])*(pow(k, cnt)) + (dp[n%10]-dp[n%10 - 1])*curr;
            }
            cnt++;
            n /= 10;
        }
        return count + curr;
    }
};