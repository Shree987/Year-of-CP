/*
Author : Shreeraksha R Aithal
Problem name : Average Salary Excluding the Minimum and Maximum Salary
Problem link : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
Difficulty : Easy
Tags : Array, Sorting
*/

class Solution {
public:
    double average(vector<int>& salary) {
        int Max = salary[0], Min = salary[0];
        double sum = 0;
        for(auto sal : salary){
            sum += sal;
            Max = max(Max, sal);
            Min = min(Min, sal);            
        }
        sum -= Max + Min;
        return sum / (salary.size()-2);
    }
};