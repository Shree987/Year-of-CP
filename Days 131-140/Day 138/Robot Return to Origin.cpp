/*
Author : Shreeraksha R Aithal
Problem name : Robot Return to Origin
Problem link : https://leetcode.com/problems/robot-return-to-origin/
Difficulty : Easy
Tags : Simulation, String
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto dir : moves){
            switch(dir){
                case 'R' : x++;     break;
                case 'L' : x--;     break;
                case 'U' : y++;     break;
                case 'D' : y--;     break;
            }
        }
        return (x == 0 && y == 0);
    }
};