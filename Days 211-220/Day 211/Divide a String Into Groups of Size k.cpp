/*
Author : Shreeraksha R Aithal
Problem name : Divide a String Into Groups of Size k
Problem link : https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
Difficulty : Easy
Tags : Simulation, String
*/

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int value = -1, i, n = tops.size(), answer = 0, sum = 0;
        for(i = 0; i < n; i++){
            if(tops[i] == bottoms[i]){
                sum++;
                if(value == -1)   value = tops[i];
                else if(value != tops[i])       return -1;
            }
        }
        if(value == -1){
            int count1 = 0, count2 = 0;
            value = tops[0];
            for(i = 0; i < n; i++){
                if(tops[i] == value)   continue;
                else if(bottoms[i] == value){
                    count1++;
                }
                else{
                    count1 = -1;
                    break;
                }
            }
            count1 = min(count1, n - sum - count1);
            value = bottoms[0];
            for(i = 0; i < n; i++){
                if(tops[i] == value)   continue;
                else if(bottoms[i] == value){
                    count2++;
                }
                else{
                    count2 = -1;
                    break;                    
                }
            }
            count2 = min(count2, n - sum - count2);
            if(count1 == -1 || count2 == -1){
                answer = 1 + count1 + count2;
            }
            else    answer = min(count1, count2);
        }
        else{
            int count = 0;
            for(i = 0; i < n; i++){
                if(tops[i] == value)   continue;
                else if(bottoms[i] == value){
                    count++;
                }
                else    return -1;
            }
            answer = min(count, n - sum - count);
        }
        return answer;
    }
};