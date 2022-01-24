/*
Author : Shreeraksha R Aithal
Problem name : Valid Number
Problem link : https://leetcode.com/problems/valid-number/
Difficulty : Hard
Tags : String
*/

class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();
        if(s[i] == '+' || s[i] == '-')      i++;
        if(i == n)  return false;
        if(s[i] == '.'){
            if(i == n-1 || !isdigit(s[i+1]))    return false;
            i++;
            while(i < n && isdigit(s[i]))   i++;
        }
        else{
            if(!isdigit(s[i]))     return false;
            while(i < n && isdigit(s[i]))   i++;
            if(i == n)  return true;
            if(s[i] == '.'){
                i++;
                while(i < n && isdigit(s[i]))   i++; 
            }
        }
        if(i == n)      return true;
        if(s[i] != 'e' && s[i] != 'E')      return false;
        i++;
        if(s[i] == '+' || s[i] == '-')      i++;
        if(i == n)      return false;
        while(i < n && isdigit(s[i]))   i++;
        return (i == n);
    }
};