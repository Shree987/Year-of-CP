/*
Author : Shreeraksha R Aithal
Problem name : Basic Calculator II
Problem link : https://leetcode.com/problems/basic-calculator-ii/
Difficulty : Medium
Tags : Math, Stack, String
*/

class Solution {
public:
    int calculate(string s) {
        char optr = ' ';
        stack<int> value;
        stack<char> opr;
        int i = 0;
        while(i < s.size()){
            while(i < s.size() && s[i] == ' ')      i++;
            if(i == s.size())   break;
            if(s[i] == '*' || s[i] == '/')      optr = s[i];
            else if(s[i] == '+' || s[i] == '-')    opr.push(s[i]);
            else{
                int val = 0;
                while(i < s.size() && isdigit(s[i])){
                    val = val*10 + (s[i]-'0');
                    i++;
                }
                if(optr == '*' || optr == '/'){
                    int val2 = value.top();
                    value.pop();
                    if(optr == '*')  val = val*val2;
                    else    val = val2/val;
                    optr = ' ';
                }
                value.push(val);
                i--;
            }
            i++;
        }
        int answer = 0;
        while(!opr.empty()){
            if(opr.top() == '-')        answer -= value.top();
            else    answer += value.top();
            opr.pop();
            value.pop();
        }
        return answer + value.top();
    }
};