/*
Author : Shreeraksha R Aithal
Problem name : Maximum Number of Words Found in Sentences
Problem link : https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
Difficulty : Easy
Tags : Array, String
*/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int answer = 0, count;
        for(auto &str : sentences){
            count = 1;
            for(auto &ch : str){
                if(ch == ' ')       count++;
            }
            answer = max(answer, count);
        }
        return answer;
    }
};