/*
Author : Shreeraksha R Aithal
Problem name : Closest Dessert Cost
Problem link : https://leetcode.com/problems/closest-dessert-cost/
Difficulty : Medium
Tags : Array, Backtracking, Dynamic Programming
*/

class Solution {
    int answer;
    void calcVal(int &target, int &val){
        if(abs(target - val) < abs(target - answer))    answer = val;
        else if(abs(target - val) == abs(target - answer))    answer = min(answer, val);
    }
    void dp(vector<int>& toppingCosts, int index, int &value, int &target){
        if(index == toppingCosts.size() || value > target)    return;
        dp(toppingCosts, index+1, value, target);
        value += toppingCosts[index];
        calcVal(target, value);
        dp(toppingCosts, index+1, value, target);
        value += toppingCosts[index];
        calcVal(target, value);
        dp(toppingCosts, index+1, value, target);
        value -= 2*toppingCosts[index];
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        sort(toppingCosts.begin(), toppingCosts.end());
        sort(baseCosts.begin(), baseCosts.end());
        answer = baseCosts[0];
        int value;
        for(int i = 0; i < baseCosts.size(); i++){
            value = baseCosts[i];
            calcVal(target, value);
            if(value > target)      break;
            dp(toppingCosts, 0, value, target);
        }
        return answer;
    }
};