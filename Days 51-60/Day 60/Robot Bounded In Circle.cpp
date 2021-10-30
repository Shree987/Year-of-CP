/*
Author : Shreeraksha R Aithal
Problem name : Robot Bounded In Circle
Problem link : https://leetcode.com/problems/robot-bounded-in-circle/
Difficulty : Medium
Tags : Math, Simulation, String
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 0, x = 0, y = 0;
        for(int i = 0; i < instructions.size(); i++){
            switch(instructions[i]){
                case 'R':   dir = (dir+1)%4;    break;
                case 'L':   dir = (dir+3)%4;    break;
                case 'G':
                    switch(dir){
                        case 0 : y++;   break;
                        case 1 : x++;   break;
                        case 2 : y--;   break;
                        case 3 : x--;   break;
                    }
                    break;
            }
        }
        return ((x==0 && y==0) || dir > 0);
    }
};