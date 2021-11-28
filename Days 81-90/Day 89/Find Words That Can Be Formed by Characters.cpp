/*
Author : Shreeraksha R Aithal
Problem name : Find Words That Can Be Formed by Characters
Problem link : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
Difficulty : Easy
Tags : Array, Hash Table, String
*/

class Solution {
    void fill(int arr1[26], int arr2[26]){
        for(int i = 0; i < 26; i++){
            arr2[i] = arr1[i];
        }
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int arr[26], arr2[26], i, j, n = 0;
        memset(arr, 0, sizeof(arr));
        for(i = 0; i < chars.size(); i++){
            arr[chars[i]-'a']++;
        }
        for(j = 0; j < words.size(); j++){
            fill(arr, arr2);
            for(i = 0; i < words[j].size(); i++){
                if(arr2[words[j][i]-'a'] == 0)      break;
                arr2[words[j][i]-'a']--;
            }
            if(i == words[j].size())    n += words[j].size();
        }
        return n;
    }
};