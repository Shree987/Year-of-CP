/*
Author : Shreeraksha R Aithal
Problem name : Boats to Save People
Problem link : https://leetcode.com/problems/boats-to-save-people/
Difficulty : Medium
Tags : Array, Greedy, Sorting, Two Pointers
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1, cnt = 0;
        while(i < j){
            if(people[i] + people[j] <= limit)      i++;
            j--;
            cnt++;
        }
        if(i == j)      cnt++;
        return cnt;
    }
};