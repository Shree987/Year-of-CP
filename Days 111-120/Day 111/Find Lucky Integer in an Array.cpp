/*
Author : Shreeraksha R Aithal
Problem name :  Find Lucky Integer in an Array
Problem link : https://leetcode.com/problems/find-lucky-integer-in-an-array/
Difficulty : Easy
Tags : Array, Counting, Hash Table
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i = arr.size()-1; i>=0; i--){
            if(i<arr.size()-1 && arr[i] == arr[i+1])    continue;
            if(i-arr[i]>=-1 && arr[i-arr[i]+1] == arr[i] && (i-arr[i] == -1 || arr[i-arr[i]] != arr[i]))      return arr[i];
        }
        return -1;
    }
};