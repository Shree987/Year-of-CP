/*
Author : Shreeraksha R Aithal
Problem name : Add Binary
Problem link : https://leetcode.com/problems/add-binary/
Difficulty : Easy
Tags : Bit Manipulation, Math, Simulation, String
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "0")    return b;
        if(b == "0")    return a;
        string s = "";
        int ai = a.size()-1, bi = b.size()-1, carry = 0;
        while(ai>=0 || bi>=0 || carry>0){
            if(ai >= 0){
                carry += (a[ai]-'0');
                ai--;
            }
            if(bi >= 0){
                carry += (b[bi]-'0');
                bi--;
            }
            s.push_back('0' + carry%2);
            carry /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};