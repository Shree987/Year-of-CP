/*
Author : Shreeraksha R Aithal
Problem name : 1-bit and 2-bit Characters
Problem link : https://leetcode.com/problems/1-bit-and-2-bit-characters/
Difficulty : Easy
Tags : Array
*/

bool isOneBitCharacter(vector<int>& bits) {
        int i;
        for(i = 0; i < bits.size()-1; i++){
            if(bits[i] == 0)    continue;
            else    i++;
        }
        return (i == bits.size()-1);
    }