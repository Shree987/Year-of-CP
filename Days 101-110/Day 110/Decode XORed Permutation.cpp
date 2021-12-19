/*
Author : Shreeraksha R Aithal
Problem name : Decode XORed Permutation
Problem link : https://leetcode.com/problems/decode-xored-permutation/
Difficulty : Medium
Tags : Array, Bit Manipulation
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size()+1;
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++){
            arr[n-1] = arr[n-1] xor i+1;
            if(i<n-1 && i%2 == 0)   arr[n-1] = arr[n-1] xor encoded[i];
        }
        for(int i = n-2; i>=0; i--){
            arr[i] = arr[i+1] xor encoded[i];
        }
        return arr;
    }
};