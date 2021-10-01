/*
Author : Shreeraksha R Aithal
Problem name : Number of Burgers with No Waste of Ingredients
Problem link : https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
Difficulty : Medium
Tags : Math
*/

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        if(tomatoSlices %2 == 1)        return ans;
        tomatoSlices /= 2;
        ans.push_back(tomatoSlices - cheeseSlices);
        ans.push_back(cheeseSlices - ans[0]);
        if(ans[0] < 0 || ans[1] < 0)    ans.clear();
        return ans;
    }
};