/*
Author : Shreeraksha R Aithal
Problem name : Vowel Spellchecker
Problem link : https://leetcode.com/problems/vowel-spellchecker/
Difficulty : Medium
Tags : Array, Hash Table, String
*/

class Solution {
    char VowelConv(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')    return 'a';
        return c;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        map<string, string> C, V;
        set<string> St;
        string cap, vowel;
        int i, n, m;
        for(auto str : wordlist){
            St.insert(str);
            cap = vowel = str;
            n = str.size();
            for(i = 0; i < n; i++){
                cap[i] = tolower(cap[i]);
                vowel[i] = VowelConv(cap[i]);
            }
            if(C.find(cap) == C.end())      C[cap] = str;
            if(V.find(vowel) == V.end())      V[vowel] = str;
        }
        for(m = 0 ; m < queries.size(); m++){
            if(St.find(queries[m]) != St.end())     continue;
            vowel = cap = queries[m];
            queries[m] = "";
            for(i = 0; i < n; i++){
                cap[i] = tolower(cap[i]);
                vowel[i] = VowelConv(cap[i]);
            }
            if(C.find(cap) != C.end())      queries[m] = C[cap];
            else    if(V.find(vowel) != V.end())      queries[m] = V[vowel];
        }
        return queries;
    }
};