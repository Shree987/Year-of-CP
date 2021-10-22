/*
Author : Shreeraksha R Aithal
Problem name : Sum of Even Numbers After Queries
Problem link : https://leetcode.com/problems/sum-of-even-numbers-after-queries/
Difficulty : Medium
Tags : Array, Simulation
*/

#define add(a)  ((a % 2 == 0)? a : 0)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer(queries.size());
        int sum = 0;
        for(auto a : nums){
            sum += add(a);
        }
        for(int i = 0; i < queries.size(); i++){
            sum -= add(nums[queries[i][1]]);
            nums[queries[i][1]] += queries[i][0];   
            sum += add(nums[queries[i][1]]);
            answer[i] = sum;
        }
        return answer;
    }
};