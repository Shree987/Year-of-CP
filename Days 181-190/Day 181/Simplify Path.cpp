/*
Author : Shreeraksha R Aithal
Problem name : Simplify Path
Problem link : https://leetcode.com/problems/simplify-path/
Difficulty : Medium
Tags : Stack, String
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0, j;
        while(i < path.size()){
            if(path[i] == '/')      i++;
            j = i;
            while(j < path.size() && path[j] != '/')        j++;
            if(i != j){
                string a = path.substr(i, j-i);
                if(a == ".."){
                    if(!st.empty())     st.pop();
                }
                else if(a != ".")   st.push(a);
            }
            else{
                j++;
            }
            i = j;
        }
        if(st.empty())  return "/";
        path = "";
        while(!st.empty()){
            path = "/" + st.top() + path;
            st.pop();
        }
        return path;
    }
};