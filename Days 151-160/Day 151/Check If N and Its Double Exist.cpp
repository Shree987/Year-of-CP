/*
Author : Shreeraksha R Aithal
Problem name : Check If N and Its Double Exist
Problem link : https://leetcode.com/problems/check-if-n-and-its-double-exist/
Difficulty : Easy
Tags : Array, Binary Search, Hash Table, Sorting, Two Pointers
*/

class Solution {    
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i, j, k = 0;
        while(k < arr.size() && arr[k] < 0)       k++;
        if(k+1 < arr.size() && arr[k+1] == 0){
            return true;
        }
        i = j = k-1;
        if(k < arr.size() && arr[k] == 0)      k++;
        while(j >= 0){
            if(arr[i]*2 == arr[j])      return true;
            if(arr[i]*2 < arr[j])      j--;
            else    i--;
        }
        i = j = k;
        while(j < arr.size()){
            if(arr[i]*2 == arr[j])      return true;
            if(arr[i]*2 > arr[j])      j++;
            else    i++;
        }
        return false;
    }
};