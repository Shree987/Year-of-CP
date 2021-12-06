/*
Author : Shreeraksha R Aithal
Problem name : Minimum Cost to Move Chips to The Same Position
Problem link : https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
Difficulty : Easy
Tags : Array, Greedy, Math
*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for(int i = 0; i < position.size(); i++){
            if(position[i]%2 == 0)    odd++;
            else    even++;
        }
        return min(odd, even);
    }
};