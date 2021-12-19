/*
Author : Shreeraksha R Aithal
Problem name : Decode String
Problem link : https://leetcode.com/problems/decode-string/
Difficulty : Medium
Tags : Recursion, Stack, String
*/

class Solution {
    int index, len;
    string decoder(string &s){
        // index points to '['
        string ans = "";
        index++;
        while(index < len){
            if(s[index] == ']'){
                index++;
                break;
            }
            if(isalpha(s[index])){
                ans.push_back(s[index]);
                index++;
            }
            else{
                //its a number
                int num = 0;
                while(index < len && isdigit(s[index])){
                    num = num*10 + (s[index]-'0');
                    index++;
                }
                string str = decoder(s);
                while(num > 0){
                    ans.insert(ans.end(), str.begin(), str.end());
                    num--;
                }
            }
        }
        return ans;
    }
public:
    string decodeString(string s) {
        index = 0;
        s = '[' + s + ']';
        len = s.size();
        return decoder(s);
    }
};