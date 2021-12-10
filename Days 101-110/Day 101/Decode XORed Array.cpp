/*
Author : Shreeraksha R Aithal
Problem name : Decode XORed Array
Problem link : https://leetcode.com/problems/decode-xored-array/
Difficulty : Easy
Tags : Array, Bit Manipulation
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        encoded.insert(encoded.begin(), first);
        for(int i = 1; i < encoded.size(); i++){
            encoded[i] = encoded[i] xor encoded[i-1];
        }
        return encoded;
    }
};