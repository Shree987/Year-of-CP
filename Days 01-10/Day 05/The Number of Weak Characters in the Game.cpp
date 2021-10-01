/*
Author : Shreeraksha R Aithal
Problem name : The Number of Weak Characters in the Game
Problem link : https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
Difficulty : Medium
Tags : Array, Greedy, Sorting
*/

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count = 0, itr, atk, def1 = 0, def2, len = properties.size();
        sort(properties.begin(), properties.end());
        def2 = properties[len-1][1];
        atk = properties[len-1][0];
        for(itr = len-2; itr>=0; itr--){
            if(properties[itr][0] < atk){                
                def1 = max(def2, def1);
                def2 = properties[itr][1];
                atk = properties[itr][0];
            }
            if(properties[itr][1] < def1)  count++;
            def2 = max(def2, properties[itr][1]);
        }
        return count;
    }
};