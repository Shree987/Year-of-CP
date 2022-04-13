/*
Author : Shreeraksha R Aithal
Problem name : Check if the Sentence Is Pangram
Problem link : https://leetcode.com/problems/check-if-the-sentence-is-pangram/
Difficulty : Easy
Tags : Hash Table, String
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> found(26, false);
        int count = 26;
        for(auto c : sentence){
            if(!found[c-'a']){
                count--;
                found[c-'a'] = true;
            }
            if(count == 0)      break;
        }
        return count == 0;
    }
};