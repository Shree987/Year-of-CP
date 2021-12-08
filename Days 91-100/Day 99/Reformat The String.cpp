/*
Author : Shreeraksha R Aithal
Problem name : Reformat The String
Problem link : https://leetcode.com/problems/reformat-the-string/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string reformat(string s) {
        string str = "";
        int i = 0, j = 0, n = s.size();
        while(true){
            while(i<n && !isalpha(s[i]))     i++;
            while(j<n && !isdigit(s[j]))     j++;
            if(i == n && j == n)    return str;
            else if(i<n && j<n){
                str.push_back(s[i]);
                str.push_back(s[j]);
            }
            else if(i == n){
                i = j+1;
                while(i<n && !isdigit(s[i]))     i++;
                if(i == n){
                    str.insert(str.begin(), s[j]);
                    return str;
                }
                else    return "";
            }
            else if(j == n){
                j = i + 1;
                while(j<n && !isalpha(s[j]))     j++;
                if(j == n){
                    str.push_back(s[i]);
                    return str;
                }
                else    return "";
            }
            i++;
            j++;
        }
        return str;
    }
};