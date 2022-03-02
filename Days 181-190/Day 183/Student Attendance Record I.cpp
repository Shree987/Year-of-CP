/*
Author : Shreeraksha R Aithal
Problem name : Student Attendance Record I
Problem link : https://leetcode.com/problems/student-attendance-record-i/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    bool checkRecord(string s) {
        bool countA = false;
        int prevL = 0;
        for(int ind = 0; ind < s.size(); ind++){
            if(s[ind] == 'L'){
                if(prevL == 2)      return false;
                else    prevL++;
            }
            else{
                prevL = 0;
                if(s[ind] == 'A'){
                    if(countA)      return false;
                    else    countA = true;
                }
            }
        }
        return true;
    }
};