/*
Author : Shreeraksha R Aithal
Problem name : Array of Doubled Pairs
Problem link : https://leetcode.com/problems/array-of-doubled-pairs/
Difficulty : Medium
Tags : Array, Greedy, Hash Table, Sorting
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> mp;
        for(auto k : arr){
            mp[k]++;
        }
        while(!mp.empty()){
            int k = (*mp.begin()).first;
            if(k == 0){
                if(mp[0]%2 == 1)    return false;
                mp.erase(0);
            }
            else if(k < 0){
                if(abs(k)%2 == 1)   return false;
                
                if(mp.find(k/2) == mp.end())    return false;
                if(mp[k/2] < mp[k])         return false;
                else if(mp[k/2] == mp[k]){
                    mp.erase(k/2);
                }
                else{
                    mp[k/2] -= mp[k];
                }
                mp.erase(k);
            }
            else{
                if(mp.find(2*k) == mp.end())    return false;
                if(mp[2*k] < mp[k])         return false;
                else if(mp[2*k] == mp[k]){
                    mp.erase(2*k);
                }
                else{
                    mp[2*k] -= mp[k];
                }
                mp.erase(k);
            }
        }
        return true;
    }
};