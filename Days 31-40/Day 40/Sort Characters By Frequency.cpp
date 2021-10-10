/*
Author : Shreeraksha R Aithal
Problem name : Sort Characters By Frequency
Problem link : https://leetcode.com/problems/sort-characters-by-frequency/
Difficulty : Medium
Tags : Bucket Sort, Counting, Hash Table, Heap (Priority Queue), Sorting, String
*/

#define f first
#define s second
class Solution {
    int hash(char c){
        if(c>='0' && c<='9')    return c-'0';
        if(c>='a' && c<='z')    return 10 + c - 'a';
        return 36 + c - 'A';
    }
public:
    string frequencySort(string s) {
        int index = 0, ptr = 0;
        vector<pair<int,char>> arr(62);
        char c = '0';
        while(index < 62){
            arr[index].s = c;
            arr[index].f = 0;
            if(c == '9')    c = 'a';
            else if(c == 'z')   c = 'A';
            else    c++;
            index++;
        }
        for(auto c : s){
            arr[hash(c)].f++;
        }
        sort(arr.rbegin(), arr.rend());
        ptr = index = 0;
        while(index < s.size() && ptr<62){
            if(arr[ptr].f == 0)    break;
            while(index < s.size() && arr[ptr].f > 0){
                s[index] = arr[ptr].s;
                arr[ptr].f--; 
                index++;
            }
            ptr++;
        }
        return s;
    }
};