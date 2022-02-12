/*
Author : Shreeraksha R Aithal
Problem name : Nim Game
Problem link : https://leetcode.com/problems/nim-game/
Difficulty : Easy
Tags : BrainTeaser, Game Theory, Math
*/

class Solution {
public:
    bool canWinNim(int n) {
        return (n%4 != 0);
    }
};