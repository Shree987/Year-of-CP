/*
Author : Shreeraksha R Aithal
Problem name : Minimum Remove to Make Valid Parentheses
Problem link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
Difficulty : Medium
Tags : String, Stack
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
                s[i] = '*';
            }
            else if(s[i] == ')' ){
                if(st.empty()){
                    s[i] = '*';
                }
                else{
                    int j = st.top();
                    st.pop();
                    s[j] = '(';
                }
            }
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};