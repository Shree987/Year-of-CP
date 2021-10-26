/*
Author : Shreeraksha R Aithal
Problem name : Divide Two Integers
Problem link : https://leetcode.com/problems/divide-two-integers/
Difficulty : Medium
Tags : Bit Manipulation, Math
*/

class Solution {
public:
    int divide(int dvd, int dvs) {
        if(dvd == 0 || abs((long)dvd) < abs((long)dvs))   return 0;
        if(dvd == INT_MIN && dvs == -1)     return INT_MAX;
        if(dvs == 1)       return dvd;
        if(dvs == -1)      return -dvd;
        int ptr, cnt = 0, limit = INT_MAX>>2, val;
        bool sign = true;
        if((dvd > 0 && dvs < 0) || (dvd < 0 && dvs > 0))    sign = false;
        if(abs((long)dvd) == abs((long)dvs))   return (sign ? 1 : -1);
        if(dvd == INT_MIN){
            cnt = 1;
            dvd += abs(dvs);
        }
        dvd = abs(dvd);
        dvs = abs(dvs);
        stack<pair<int,int>> st;
        ptr = 1;
        val = dvs;
        while(val < dvd){
            st.push({val, ptr});
            if(val >= limit)    break;
            ptr = (ptr << 1);
            val = (val << 1);
        }
        while(dvd > 0 && !st.empty()){
            while(st.top().first <= dvd){
                cnt += st.top().second;
                dvd -= st.top().first;
            }
            st.pop();            
        }
        return (sign ? cnt : -cnt);
    }
};