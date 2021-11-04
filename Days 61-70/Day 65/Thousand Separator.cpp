/*
Author : Shreeraksha R Aithal
Problem name : Thousand Separator
Problem link : https://leetcode.com/problems/thousand-separator/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string thousandSeparator(int n) {
        string s = string(1,char('0' + n%10));
        n /= 10;
        while(n>0){
            s.push_back(char('0' + n%10));
            n /= 10;
            if(n == 0)  break;
            s.push_back(char('0' + n%10));
            n /= 10;
            if(n == 0)  break;
            s = s + "." + char('0' + n%10);
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};