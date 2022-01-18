/*
Author : Shreeraksha R Aithal
Problem name : Day of the Week
Problem link : https://leetcode.com/problems/day-of-the-week/
Difficulty : Easy
Tags : Math
*/

class Solution {
public:
    bool leapYear(int year){
        if(year%400 == 0)     return true;
        return (year%100 != 0 && year%4 == 0);
    }
    int yearCal(int year){
        int yr = 1971, extra = 0;
        while(year != yr){
            if(leapYear(yr))      extra+=2;
            else    extra++;
            yr++;
        }
        return extra%7;
    }    
    int monthCal(int month, int yr){
        int days = 0;
        vector<int> arr = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(month > 2 && leapYear(yr)){
            days++;
        }
        for(int m = 0; m < month-1; m++){
            days += arr[m];
        }
        return days;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int days = (3 + yearCal(year) + monthCal(month, year) + day)%7;     // Monday = 0
        switch(days){
            case 0 : return "Monday";
            case 1 : return "Tuesday";
            case 2 : return "Wednesday";
            case 3 : return "Thursday";
            case 4 : return "Friday";
            case 5 : return "Saturday";
            case 6 : return "Sunday";
        }
        return "";
    }
        
};