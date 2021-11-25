/*
Author : Shreeraksha R Aithal
Problem name : Happy Number
Problem link : https://leetcode.com/problems/happy-number/
Difficulty : Easy
Tags : Hash Table, Math, Two Pointers
*/

class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        st.insert(n);
        while(n > 1){
            int m = 0;
            while(n>0){
                m += (n%10)*(n%10);
                n /= 10;
            }
            if(m == 1)      return true;
            n = m;
            if(st.find(n) != st.end())      return false;
            st.insert(n);
        }
        return true;
    }
};