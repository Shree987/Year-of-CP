/*
Author : Shreeraksha R Aithal
Problem name : Remove Outermost Parentheses
Problem link : https://leetcode.com/problems/remove-outermost-parentheses/
Difficulty : Easy
Tags : Stack, String
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(st.size() == 1){
                    s[st.top()] = '*';
                    s[i] = '*';
                }
                st.pop();
            }
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};