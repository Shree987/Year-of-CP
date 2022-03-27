/*
Author : Shreeraksha R Aithal
Problem name : Delete Characters to Make Fancy String
Problem link : https://leetcode.com/problems/delete-characters-to-make-fancy-string/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string makeFancyString(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(st.size() < 2)       st.push(i);
            else{
                if(s[st.top()] != s[i]){
                    st.push(i);
                }
                else{
                    int ind = st.top();
                    st.pop();
                    if(s[st.top()] == s[i]){
                        s[i] = '*';
                        st.push(ind);
                    }
                    else{
                        st.push(ind);
                        st.push(i);
                    }
                }
            }
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};