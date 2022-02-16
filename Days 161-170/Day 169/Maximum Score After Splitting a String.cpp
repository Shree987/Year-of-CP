/*
Author : Shreeraksha R Aithal
Problem name : Maximum Score After Splitting a String
Problem link : https://leetcode.com/problems/maximum-score-after-splitting-a-string/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    int maxScore(string s) {
        int num1 = 0, num2 = 0, total = 0;
        for(int i = s.size()-1; i > 0; i--){
            if(s[i] == '1')     num2++;
        }
        if(s[0] == '0')     num1 = 1;
        total = num1 + num2;
        for(int i = 1; i < s.size()-1; i++){
            if(s[i] == '1'){
                num2--;
            }
            else{
                num1++;
            }
            total = max(total, num1+num2);
        }
        return total;
    }
};