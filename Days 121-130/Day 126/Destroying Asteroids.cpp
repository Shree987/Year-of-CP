/*
Author : Shreeraksha R Aithal
Problem name : Destroying Asteroids
Problem link : https://leetcode.com/problems/destroying-asteroids/
Difficulty : Medium
Tags : Array, Greedy, Sorting
*/

class Solution {
public:
    bool asteroidsDestroyed(long mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i < asteroids.size(); i++){
            if(mass >= asteroids[i])    mass += asteroids[i];
            else    return false;
        }
        return true;
    }
};