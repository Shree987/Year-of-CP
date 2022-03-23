/*
Author : Shreeraksha R Aithal
Problem name : Sell Diminishing-Valued Colored Balls
Problem link : https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
Difficulty : Medium
Tags : Array, Binary Search, Greedy, Heap (Priority Queue), Math, Sorting
*/

#define Max 1000000007
class Solution {
    int calculateSum(int start, int end){
        long long sum1 = start, sum2 = end;
        sum1 = ((sum1*(sum1+1))/2)%Max;
        sum2 = ((sum2*(sum2+1))/2)%Max; 
        return (sum1 - sum2 + 2*Max)%Max;
    }
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(), inventory.rend());
        inventory.push_back(0);
        long long sum = 0;
        int itr1 = 0;
        while(orders > 0 && itr1 < inventory.size()){
            while(itr1 < inventory.size() && inventory[0] == inventory[itr1])      itr1++;
            long long len = itr1, diff = inventory[0] - inventory[itr1];
            if(len*diff <= orders){
                orders -= len*diff;
                diff = calculateSum(inventory[0], inventory[itr1]);
                sum = (sum + (diff*len)%Max)%Max;
            }
            else{                
                long long rem = orders%len, div = orders/len;
                diff = calculateSum(inventory[0], inventory[0]-div);
                sum = (sum + (diff*len)%Max)%Max;
                inventory[0] -= div;
                sum = (sum + inventory[0]*rem)%Max;
                orders = 0;
            }
            inventory[0] = inventory[itr1];
        }
        return sum%Max;
    }
};