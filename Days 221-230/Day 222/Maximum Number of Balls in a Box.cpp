/*
Author : Shreeraksha R Aithal
Problem name : Maximum Number of Balls in a Box
Problem link : https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
Difficulty : Easy
Tags : Counting, Hash Table, Math
*/

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> mp;
        int Max_count = 0;
        for(int n = lowLimit; n <= highLimit; n++){
            int sum = 0, num = n;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            Max_count = max(Max_count, ++mp[sum]);
        }
        return Max_count;
    }
};