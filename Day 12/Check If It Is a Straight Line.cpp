/*
Author : Shreeraksha R Aithal
Problem name : Check If It Is a Straight Line
Problem link : https://leetcode.com/problems/check-if-it-is-a-straight-line/
Difficulty : Easy
Tags : Array, Geometry, Math
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool N = true, M = true;
        int num, den, temp, num2, den2;
        for(int temp = 1; (N | M) && temp < coordinates.size(); temp++){
            if(coordinates[temp][0] != coordinates[0][0])  N = false;
            if(coordinates[temp][1] != coordinates[0][1])  M = false;
        }
        if(temp == coordinates.size())     return true;
        num = coordinates[1][1] - coordinates[0][1];
        den = coordinates[1][0] - coordinates[0][0];
        temp = __gcd(num, den);
        num /= temp;
        den /= temp;
        for(int i = 1; i < coordinates.size(); i++){
            num2 = coordinates[i][1] - coordinates[0][1];
            den2 = coordinates[i][0] - coordinates[0][0];
            temp = __gcd(num2, den2);
            num2 /=temp;
            den2 /= temp;
            if(num != num2 || den != den2)      return false;
        }
        return true;
    }
};