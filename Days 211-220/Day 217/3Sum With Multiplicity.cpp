/*
Author : Shreeraksha R Aithal
Problem name : 3Sum With Multiplicity
Problem link : https://leetcode.com/problems/3sum-with-multiplicity/
Difficulty : Medium
Tags : Array, Counting, Hash Table, Sorting, Two Pointers
*/

#define m 1000000007
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        for(auto &num : arr){
            mp[num]++;
        }
        sort(arr.begin(), arr.end());
        int i, j, k, n = arr.size(), cnt = 0;
        long sum;
        for(i = 0; i+2 < n;){
            j = i+1;
            while(j<n){
                if(target - arr[i] - arr[j] == arr[j]){
                    if(arr[i] == arr[j]){
                        sum = mp[arr[j]]*(mp[arr[j]]-1);
                        sum = ((sum*(mp[arr[j]]-2))/6 ) %m;
                        cnt = (cnt + sum)%m;
                    }
                    else{
                        sum = mp[arr[j]]*(mp[arr[j]]-1);
                        sum = ((sum*mp[arr[i]])/2 ) %m;
                        cnt = (cnt + sum)%m;
                    }
                }
                else if(target - arr[i] - arr[j] > arr[j]){
                    if(arr[i] == arr[j]){
                        sum = mp[arr[j]]*(mp[arr[j]]-1);
                        sum = ((sum*mp[target - arr[i] - arr[j]])/2 ) %m;
                        cnt = (cnt + sum)%m;
                    }
                    else{
                        sum = mp[arr[j]]*(mp[target - arr[i] - arr[j]]);
                        sum = (sum*mp[arr[i]]) %m;
                        cnt = (cnt + sum)%m;
                    }
                }
                k = j;
                while(j < n && arr[j] == arr[k])       j++;
            }
            k = i;
            while(i < n && arr[i] == arr[k])       i++;
        }
        return cnt;
    }
};