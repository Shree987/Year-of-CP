/*
Author : Shreeraksha R Aithal
Problem name : Largest Substring Between Two Equal Characters
Problem link : https://leetcode.com/problems/largest-substring-between-two-equal-characters/
Difficulty : Easy
Tags : Hash Table, String
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> index(26, -1);
        int i, ans = -1;
        for(int i = 0; i < s.size(); i++){
            if(index[s[i]-'a'] == -1){
                index[s[i]-'a'] = i;
            }
            else    ans = max(ans, i - index[s[i]-'a']-1);

        }
        return ans;
    }
};