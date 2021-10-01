/*
Author : Shreeraksha R Aithal
Problem name : Slowest Key
Problem link : https://leetcode.com/problems/slowest-key/
Difficulty : Easy
Tags : Array, String
*/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int index = 0, itr;
        for(itr = releaseTimes.size()-1; itr>0; itr--){
            releaseTimes[itr] -= releaseTimes[itr-1];
            if(releaseTimes[itr] > releaseTimes[index])
                index = itr;
            else if(releaseTimes[itr] == releaseTimes[index] && keysPressed[itr] > keysPressed[index])
                index = itr;
        }
        return keysPressed[index];
    }
};