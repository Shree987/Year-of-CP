/*
Author : Shreeraksha R Aithal
Problem name : Make The String Great
Problem link : https://leetcode.com/problems/make-the-string-great/
Difficulty : Easy
Tags : Stack, String
*/

class Solution {
public:
    string makeGood(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty())      st.push(i);
            else if(tolower(s[st.top()]) == tolower(s[i]) && s[st.top()] != s[i]){
                s[st.top()] = s[i] = '*';
                st.pop();
            }
            else    st.push(i);
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};