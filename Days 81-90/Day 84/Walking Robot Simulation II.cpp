/*
Author : Shreeraksha R Aithal
Problem name : Walking Robot Simulation II
Problem link : https://leetcode.com/problems/walking-robot-simulation-ii/
Difficulty : Medium
Tags : Design, Simulation
*/

class Robot {
public:
    int w, h, dir;
    vector<int> pos;
    Robot(int width, int height) {
        pos.resize(2);
        pos[0] = pos[1] = dir = 0;
        w = width;
        h = height;
    }
    
    void step(int steps) {
        if(steps % (2*(w+h-2)) == 0){
            if(dir == 2 && pos[0] == w-1)    dir = 1;
            else if(dir == 3 && pos[1] == h-1)    dir = 2;
            else if(dir == 0 && pos[0] == 0)    dir = 3;
            else if(dir == 1 && pos[1] == 0)    dir = 0;
        }
        steps = steps%(2*(w+h-2));
        while(steps>0){
            if(dir == 0 && pos[0] == w-1)    dir = 1;
            else if(dir == 1 && pos[1] == h-1)    dir = 2;
            else if(dir == 2 && pos[0] == 0)    dir = 3;
            else if(dir == 3 && pos[1] == 0)    dir = 0;
            
            if(dir == 0){                
                if(pos[0] == w-1)    dir = 1;
                if(w > steps + pos[0]){
                    pos[0] += steps;
                    steps = 0;
                }
                else{
                    steps -= w - pos[0] - 1;
                    pos[0] = w-1;
                }
            }
            else if(dir == 1){
                if(h > steps+pos[1]){
                    pos[1] += steps;
                    steps = 0;
                }
                else{
                    steps -= h - pos[1] - 1;
                    pos[1] = h-1;
                }
            }
            else if(dir == 2){
                if(0 <= pos[0] - steps){
                    pos[0] -= steps;
                    steps = 0;
                }
                else{
                    steps -= pos[0];
                    pos[0] = 0;
                }
            }
            else {
                if(0 <= pos[1] - steps){
                    pos[1] -= steps;
                    steps = 0;
                }
                else{
                    steps -= pos[1];
                    pos[1] = 0;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        switch(dir){
            case 0 : return "East";
            case 1 : return "North";
            case 2 : return "West";
            case 3 : return "South";
        }
        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */