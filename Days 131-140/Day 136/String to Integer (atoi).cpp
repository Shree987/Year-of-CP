/*
Author : Shreeraksha R Aithal
Problem name : String to Integer (atoi)
Problem link : https://leetcode.com/problems/string-to-integer-atoi/
Difficulty : Medium
Tags : String
*/

class Solution {
public:
    int myAtoi(string s) {
        int count = 0, i = 0, n = s.size(), plus = 1;
        while(i < n && s[i] == ' ')     i++;
        if(i == n)      return 0;
        if(s[i] == '+' || s[i] == '-'){
            if(s[i] == '-')   plus = -1;
            i++;
        }
        if(i == n)      return 0;
        // INT_MAX = 2147483647
        while(i < n && count < 100000000){
            if(isdigit(s[i])){
                count = count*10 + (s[i] - '0');
            }
            else{
                return count*plus;
            }
            i++;
        }
        if(i == n)      return count*plus;
        if(i < n && count < 1000000000){
            count *= plus;
            if(!isdigit(s[i]))      return count;
            if(count < 0){
                if(count < INT_MIN/10)      return INT_MIN;
                if(i+1<n && isdigit(s[i+1]))    return INT_MIN;
                if(count == INT_MIN/10){
                    if(s[i] == '9')     return INT_MIN; 
                }
                count = count*10 - (s[i]-'0');
            }
            else{
                if(count > INT_MAX/10)      return INT_MAX;
                if(i+1<n && isdigit(s[i+1]))    return INT_MAX;
                if(count == INT_MAX/10){
                    if(s[i] > '7')     return INT_MAX; 
                }
                count = count*10 + (s[i]-'0');
            }
        }
        return count;
    }
};