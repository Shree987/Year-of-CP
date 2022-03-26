/*
Author : Shreeraksha R Aithal
Problem name : Minimum Index Sum of Two Lists
Problem link : https://leetcode.com/problems/minimum-index-sum-of-two-lists/
Difficulty : Easy
Tags : Array, Hash Table, String
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> vs;
        int sum = INT_MAX;
        map<string, int> mp;
        for(int index = 0; index < list1.size(); index++){
            mp[list1[index]] = index;
        }
        for(int index = 0; index < list2.size(); index++){
            if(mp.find(list2[index]) != mp.end()){
                int newSum = index + mp[list2[index]];
                if(newSum == sum)   vs.push_back(list2[index]);
                else if(newSum < sum){
                    vs = {list2[index]};
                    sum = newSum;
                }
            }
        }
        return vs;
    }
};