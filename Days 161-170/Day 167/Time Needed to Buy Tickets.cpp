/*
Author : Shreeraksha R Aithal
Problem name : Time Needed to Buy Tickets
Problem link : https://leetcode.com/problems/time-needed-to-buy-tickets/
Difficulty : Easy
Tags : Array, Queue, Simulation
*/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for(int i = 0; i < tickets.size(); i++){
            if(i > k){
                time += min(tickets[k]-1, tickets[i]);
            }
            else{
                time += min(tickets[k], tickets[i]);
            }
        }
        return time;
    }
};