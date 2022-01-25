/*
Author : Shreeraksha R Aithal
Problem name : Goal Parser Interpretation
Problem link : https://leetcode.com/problems/goal-parser-interpretation/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string interpret(string command) {
        string str = "";
        for(int i = 0; i < command.size(); i++){
            if(command[i] == 'G')       str.push_back('G');
            if(command[i] == '('){
                if(command[i+1] == ')'){
                    str.push_back('o');
                    i++;
                }
                else{
                    str.push_back('a');
                    str.push_back('l');
                    i+=3;
                }
            }
        }
        return str;
    }
};