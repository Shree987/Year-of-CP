/*
Author : Shreeraksha R Aithal
Problem name : Number of Students Unable to Eat Lunch
Problem link : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
Difficulty : Easy
Tags : Array, Queue, Simulation, Stack
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0, length = 0, n = students.size(), i = 0, j = 0;
        length = n;
        while(j<n && length > count){
            if(students[i] == -1){
                i = (i+1)%n;
                continue;
            }
            if(sandwiches[j] == students[i]){
                students[i] = -1;
                j++;
                count = 0;
                length--;
            }
            else{
                count++;
            }
            i = (i+1)%n;            
        }
        return length;
    }
};