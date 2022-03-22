/*
Author : Shreeraksha R Aithal
Problem name : Smallest String With A Given Numeric Value
Problem link : https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
Difficulty : Medium
Tags : Greedy, String
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string str(n, 'a');
        int index = n-1;
        k -= n;
        while(k > 0){
            if(k <= 25){
                str[index] += k;
                k = 0;
            }
            else{
                k -= 25;
                str[index] = 'z';
                index--;
            }
        }
        return str;
    }
};