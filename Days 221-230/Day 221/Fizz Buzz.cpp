/*
Author : Shreeraksha R Aithal
Problem name : Fizz Buzz
Problem link : https://leetcode.com/problems/fizz-buzz/
Difficulty : Easy
Tags : Math, Simulation, String
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int index = 1; index <= n; index++){
            if(index%3 == 0 && index%5 == 0)        ans[index-1] = "FizzBuzz";
            else if(index%3 == 0)        ans[index-1] = "Fizz";
            else if(index%5 == 0)        ans[index-1] = "Buzz";
            else    ans[index-1] = to_string(index);
        }
        return ans;
    }
};