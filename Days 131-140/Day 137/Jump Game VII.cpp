/*
Author : Shreeraksha R Aithal
Problem name : Jump Game VII
Problem link : https://leetcode.com/problems/jump-game-vii/
Difficulty : Medium
Tags : Prefix sum, String, Two Pointers
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), m, k, low, high;
        k = -n-n;
        if(s[n-1] == '1')       return false;
        vector<int> arr(n, -1);
        queue<int> q;
        arr[0] = 0;
        q.push(0);
        while(!q.empty()){
            m = q.front();
            q.pop();
            if(m == n-1)    return true;
            arr[m] = 1;
            high = min(m + maxJump, n-1);
            low = max(k + maxJump+1, m + minJump);
            k = m;
            for(int i = low; i <= high; i++){
                if(s[i] == '0'){
                    if(i == n-1)    return true;
                    if(arr[i] == -1){
                        arr[i] = 0;
                        q.push(i);
                    }
                    else    break;
                }
            }
        }
        return false;
    }
};