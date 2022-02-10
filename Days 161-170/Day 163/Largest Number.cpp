/*
Author : Shreeraksha R Aithal
Problem name : Largest Number
Problem link : https://leetcode.com/problems/largest-number/
Difficulty : Medium
Tags : Greedy, String, Sorting
*/

bool cmp(const int &a, const int &b){
    long num1 = stol(to_string(a) + to_string(b)), num2 = stol(to_string(b) + to_string(a));
    return (num1 > num2);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0)        return "0";
        string ans = "";
        for(auto &num : nums){
            ans = ans + to_string(num);
        }
        return ans;
    }
};