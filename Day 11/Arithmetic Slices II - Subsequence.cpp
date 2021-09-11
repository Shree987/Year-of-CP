/*
Author : Shreeraksha R Aithal
Problem name : Arithmetic Slices II - Subsequence
Problem link : https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
Difficulty : Hard
Tags : Array, Dynamic Programming
*/

#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<ll, int>> mp(nums.size());
        int i, j, n = nums.size();
        ll diff, sum, ans = 0;
        for(i = 1; i < n; i++){
            for(j = 0; j < i; j++){
                diff = (ll)nums[i] - (ll)nums[j];
                sum = 0;
                if(mp[j].find(diff) != mp[j].end())
                    sum = mp[j][diff];
                ans += sum;
                mp[i][diff] += sum+1;
            }
        }
        return (int)ans;
    }
};