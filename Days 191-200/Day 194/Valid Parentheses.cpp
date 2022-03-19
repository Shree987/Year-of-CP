/*
Author : Shreeraksha R Aithal
Problem name : Valid Parentheses
Problem link : https://leetcode.com/problems/valid-parentheses/
Difficulty : Easy
Tags : Stack, String
*/

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1)       return false;
        stack<char> st;
        for(auto &c : s){
            if(c == '(' || c == '[' || c == '{')        st.push(c);
            else{
                if(st.empty())  return false;
                if(c == ')' && st.top() == '('){
                    st.pop();
                }
                else if(c == ']' && st.top() == '['){
                    st.pop();
                }
                else if(c == '}' && st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};