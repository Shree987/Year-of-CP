/*
Author : Shreeraksha R Aithal
Problem name : Greatest Common Divisor of Strings
Problem link : https://leetcode.com/problems/greatest-common-divisor-of-strings/
Difficulty : Easy
Tags : Math, String
*/

class Solution {
public:
    bool check(string str1, string str2, int len){
        for(int i = len; i < str1.size() || i < str2.size(); i++){
            if(i < str1.size() && str1[i] != str1[i%len])       return false;
            if(i < str2.size() && str2[i] != str2[i%len])       return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int n, len = __gcd(str1.size(), str2.size());
        for(n = 0; n < len; n++){
            if(str1[n] != str2[n])  break;
        }
        while(n > 0){
            if(len%n == 0){
                if(check(str1, str2, n))    return str1.substr(0,n);
            }
            n--;
        }
        return "";
    }
};