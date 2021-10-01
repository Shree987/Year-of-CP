/*
Author : Shreeraksha R Aithal
Problem name : Multiply Strings
Problem link : https://leetcode.com/problems/multiply-strings/
Difficulty : Medium
Tags : Math, Simulation, String
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")      return "0";
        string res(2 + num1.size() + num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i, j, carry, num, k;
        for(i = 0; i < num1.size(); i++){
            if(num1[i] == '0')      continue;
            carry = 0;
            num = num1[i]-'0';
            k = i;
            for(j = 0; j < num2.size(); j++){
                carry += (res[k]-'0') + (num*(num2[j]-'0'));
                res[k] = (carry%10 + '0');
                carry /= 10;
                k++;
            }
            while(carry > 0){
                res[k] = (carry%10 + '0');
                carry /= 10;
                k++;
            }
        }
        j = res.size()-1;
        while(j>=0 && res[j] == '0')    j--;
        res = res.substr(0, j+1);
        reverse(res.begin(), res.end());
        return res;
    }
};