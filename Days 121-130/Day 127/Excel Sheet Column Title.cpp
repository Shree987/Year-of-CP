/*
Author : Shreeraksha R Aithal
Problem name : Excel Sheet Column Title
Problem link : https://leetcode.com/problems/excel-sheet-column-title/
Difficulty : Easy
Tags : Math, String
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";
        while(columnNumber > 0){
            columnNumber -= 1;
            title.push_back('A' + columnNumber%26);
            columnNumber /= 26;
        }
        reverse(title.begin(), title.end());
        return title;
    }
};