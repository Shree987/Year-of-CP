/*
Author : Shreeraksha R Aithal
Problem name : Baseball Game
Problem link : https://leetcode.com/problems/baseball-game/
Difficulty : Easy
Tags : Array, Simulation, Stack
*/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int sum = 0, a, b;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "C"){
                sum -= st.top();
                st.pop();
            }
            else if(ops[i] == "D"){
                a = st.top();
                sum += a+a;
                st.push(a+a);
            }
            else if(ops[i] == "+"){
                a = st.top();
                st.pop();
                b = st.top();
                st.push(a);
                st.push(a+b);
                sum += a+b;
            }
            else{
                a = stoi(ops[i]);
                sum += a;
                st.push(a);
            }
        }
        return sum;
    }
};