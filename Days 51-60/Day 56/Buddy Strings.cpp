/*
Author : Shreeraksha R Aithal
Problem name : Buddy Strings
Problem link : https://leetcode.com/problems/buddy-strings/
Difficulty : Easy
Tags : Hash Table, String
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())     return false;
        bool arr[26];
        memset(arr, false, sizeof(arr));
        int i, x = -1, y = -1;
        bool present = false;
        for(i = 0; i < s.size(); i++){
            if(s[i] != goal[i]){
                if(x == -1)     x = i;
                else if(y == -1)    y = i;
                else    return false;
            }
            if(arr[s[i]-'a'])   present = true;
            arr[s[i]-'a'] = true;
        }
        if((x == -1) ^ (y == -1))   return false;
        if(x>-1 & y>-1){
            swap(s[x], s[y]);
            return (s[x]==goal[x] && s[y]==goal[y]);
        }
        return present;
    }
};