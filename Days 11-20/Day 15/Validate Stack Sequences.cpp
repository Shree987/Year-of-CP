/*
Author : Shreeraksha R Aithal
Problem name : Validate Stack Sequences
Problem link : https://leetcode.com/problems/validate-stack-sequences/
Difficulty : Medium
Tags : Array, Simulation, Stack
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i, j, n = popped.size();
        i = j = 0;
        stack<int> st;
        while(i<n){
            st.push(pushed[i]);
            i++;
            while(j<n && !st.empty()){
                if(popped[j] == st.top()){
                    st.pop();
                    j++;
                }
                else    break;
            }
        }
        return j == n;
    }
};