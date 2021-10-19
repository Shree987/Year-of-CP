/*
Author : Shreeraksha R Aithal
Problem name : Next Greater Element III
Problem link : https://leetcode.com/problems/next-greater-element-iii/
Difficulty : Medium
Tags : Math, String, Two Pointers
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int m, i;
        n = str.size();
        for(m = n-1; m>0; m--){
            if(str[m] > str[m-1]){
                for(i = m; i < n; i++){
                    if(str[i] <= str[m-1]){
                        swap(str[i-1], str[m-1]);
                        break;
                    }
                }
                if(i == n){
                    swap(str[n-1], str[m-1]);
                }
                sort(str.begin()+m, str.end());
                break;
            }
        }
        if(m == 0)  return -1;
        if(n == 10){
            m = stoi(str.substr(0, 9));
            if(m > INT_MAX/10)  return -1;
            if(m == INT_MAX/10 && str[9]-'0' > INT_MAX%10)  return -1;
        }
        return stoi(str);
    }
};