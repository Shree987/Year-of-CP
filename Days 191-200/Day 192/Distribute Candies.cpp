/*
Author : Shreeraksha R Aithal
Problem name : Distribute Candies
Problem link : https://leetcode.com/problems/distribute-candies/
Difficulty : Easy
Tags : Array, Hash Table
*/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(auto &k : candyType){
            st.insert(k);
        }
        return min(candyType.size()/2, st.size());
    }
};