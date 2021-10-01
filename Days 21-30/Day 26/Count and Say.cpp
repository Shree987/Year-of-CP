/*
Author : Shreeraksha R Aithal
Problem name : Count and Say
Problem link : https://leetcode.com/problems/count-and-say/
Difficulty : Medium
Tags : String
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)  return "1";        
        string ans = "1", res = "";
        int count, i, j;
        while(n>1){
            n--;
            res = "";
            for(i = 0; i < ans.size();){
                j = i+1;
                while(ans[i] == ans[j])     j++;
                count = j - i;
                res = res + to_string(count);
                res.push_back(ans[i]);
                i = j;
            }
            ans = res;
        }
        return ans;
    }
};