/*
Author : Shreeraksha R Aithal
Problem name : Making File Names Unique
Problem link : https://leetcode.com/problems/making-file-names-unique/
Difficulty : Medium
Tags : Array, Hash Table, String
*/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> answer(names);
        unordered_map<string, int> st;
        string str;
        for(int i = 0; i < names.size(); i++){
            if(st.find(names[i]) == st.end()){
                st[names[i]]++;
                str = names[i];
            }
            else{
                str = names[i];
                while(st.find(str) != st.end()){
                    str = names[i] + "(" + to_string(st[names[i]]) + ")";
                    st[names[i]]++;
                }
                st[str] = 1;
            }
            answer[i] = str;
        }
        return answer;
    }
};