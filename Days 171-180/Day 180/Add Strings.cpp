/*
Author : Shreeraksha R Aithal
Problem name : Add Strings
Problem link : https://leetcode.com/problems/add-strings/
Difficulty : Easy
Tags : Math, Simulation, String
*/

class Solution {
    char addVal(char c1, char c2, int &carry){
        int sum = carry + (c1 - '0') + (c2 - '0');
        carry = sum/10;
        return (char)('0' + sum%10);
    }
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size())   swap(num1, num2);
        int carry = 0, ind1 = num1.size()-1, ind2 = num2.size()-1;
        while(ind2 >= 0){
            num1[ind1] = addVal(num1[ind1], num2[ind2], carry);
            ind1--;
            ind2--;
        }
        while(ind1 >= 0){
            num1[ind1] = addVal(num1[ind1], '0', carry);
            ind1--;
        }
        if(carry == 1)      num1.insert(num1.begin(), '1');
        return num1;
    }
};