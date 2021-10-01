/*
Author : Shreeraksha R Aithal
Problem name : Reduce Array Size to The Half
Problem link : https://leetcode.com/problems/reduce-array-size-to-the-half/
Difficulty : Medium
Tags : Array, Greedy, Hash Table, Heap, Sorting
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> v;
        map<int, int> mp;
        for(auto a : arr){
            if(mp.find(a) == mp.end()){
                mp[a] = v.size();
                v.push_back(1);
            }
            else{
                v[mp[a]]++;
            }
        }
        sort(v.rbegin(), v.rend());
        int cnt = 0, sum = arr.size()/2;
        for(auto k : v){
            sum -= k;
            cnt++;
            if(sum <= 0)    return cnt;
        }
        return cnt;
    }
};