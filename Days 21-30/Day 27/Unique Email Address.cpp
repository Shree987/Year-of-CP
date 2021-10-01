/*
Author : Shreeraksha R Aithal
Problem name : Unique Email Addresses
Problem link : https://leetcode.com/problems/unique-email-addresses/
Difficulty : Easy
Tags : Array, Hash Table, String
*/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        bool domain, plus;
        string str;
        set<string> st;
        for(auto mail : emails){
            plus = domain = false;
            str = "";
            for(auto c : mail){
                if(c == '@'){   str.push_back('@');    domain = true;   }
                else if(c == '.'){
                    if(domain)      str.push_back(c);                    
                }
                else if(c == '+'){
                    if(!domain)      plus = true;
                    else    str.push_back(c);
                }
                else{
                    if(domain || !plus)     str.push_back(c);
                }
            }
            st.insert(str);
        }
        return st.size();
    }
};