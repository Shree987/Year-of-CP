/*
Author : Shreeraksha R Aithal
Problem name : Reformat Phone Number
Problem link : https://leetcode.com/problems/reformat-phone-number/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string reformatNumber(string number) {
        int i, j = 0, n = number.size();
        for(i = 0; i < n; i++){
            if(isdigit(number[i]))  number[j++] = number[i];
        }
        n = j;
        string res = "";
        i = 0;
        while(i < n-4){
            res = res + number.substr(i, 3) + "-";
            i += 3;
        }
        if(i+2 == n)    res = res + number.substr(i, 2);
        else if(i+3 == n)    res = res + number.substr(i, 3);
        else{
            res = res + number.substr(i, 2) + "-" + number.substr(i+2, 2);
        }
        return res;
    }
};