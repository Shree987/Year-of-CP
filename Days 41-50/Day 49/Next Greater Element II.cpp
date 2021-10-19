/*
Author : Shreeraksha R Aithal
Problem name : Next Greater Element II
Problem link : https://leetcode.com/problems/next-greater-element-ii/
Difficulty : Medium
Tags : Array, Monotonic Stack, Stack
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size()), arr;
        stack<int> st;
        queue<int> q;
        int i;
        for(i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i])   st.pop();
            if(st.empty()){     res[i] = -1;      q.push(i);  }
            else    res[i] = st.top();
            st.push(nums[i]);
        }
        while(!q.empty()){
            i = q.front();
            q.pop();
            while(!st.empty() && st.top() <= nums[i])   st.pop();
            if(st.empty())      break;
            res[i] = st.top();
        }
        return res;
    }
};