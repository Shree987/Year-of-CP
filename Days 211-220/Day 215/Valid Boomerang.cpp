/*
Author : Shreeraksha R Aithal
Problem name : Valid Boomerang
Problem link : https://leetcode.com/problems/valid-boomerang/
Difficulty : Easy
Tags : Geometry, Math
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(points[0] == points[1] || points[1] == points[2] || points[0] == points[2])      return false;
        int m1_n = points[1][1] - points[2][1], m1_d = points[1][0] - points[2][0];
        int m2_n = points[0][1] - points[2][1], m2_d = points[0][0] - points[2][0];
        if(m1_d == 0 && m2_d == 0)      return false;
        else if(m1_d == 0 || m2_d == 0)     return true;
        if(m1_n == 0 && m2_n == 0)      return false;
        else if(m1_n == 0 || m2_n == 0)     return true;
        
        int b1 = ((m1_n > 0) xor (m1_d > 0)), b2 = ((m2_n > 0) xor (m2_d > 0));
        if(b1 != b2)        return true;
        m1_n = abs(m1_n);
        m2_n = abs(m2_n);
        m1_d = abs(m1_d);
        m2_d = abs(m2_d);
        
        int gcd = __gcd(m1_n, m1_d);
        m1_n /= gcd;
        m1_d /= gcd;
        
        gcd = __gcd(m2_n, m2_d);
        m2_n /= gcd;
        m2_d /= gcd;
        return !((m1_n == m2_n) && (m1_d == m2_d));
    }
};