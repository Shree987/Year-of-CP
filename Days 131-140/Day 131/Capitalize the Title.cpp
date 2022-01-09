/*
Author : Shreeraksha R Aithal
Problem name : Capitalize the Title
Problem link : https://leetcode.com/problems/capitalize-the-title/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string capitalizeTitle(string title) {
        int start = 0, end = 0;
        while(start < title.size()){
            end = start;
            while(end < title.size() && title[end] != ' '){
                title[end] = tolower(title[end]);
                end++;
            }
            if(end-start > 2){
                title[start] = toupper(title[start]);
            }
            start = end+1;
        }
        return title;
    }
};