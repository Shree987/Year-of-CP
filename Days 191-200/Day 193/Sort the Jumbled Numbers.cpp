/*
Author : Shreeraksha R Aithal
Problem name : Sort the Jumbled Numbers
Problem link : https://leetcode.com/problems/sort-the-jumbled-numbers/
Difficulty : Medium
Tags : Array, Sorting
*/

#define f first
#define s second
class Solution {
    bool cmp(pair<int, pair<int, int>>& p1, pair<int, pair<int, int>>&p2){
        if(p1.f != p2.f){
            return p1.f < p2.f;
        }
        return p1.s.f < p2.s.f;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int i, n = nums.size(), dec;
        vector<pair<int, pair<int, int>>> vp(n);
        for(i = 0; i < n; i++){
            vp[i] = {0, {i, nums[i]}};
            if(nums[i] == 0)        vp[i].f = mapping[0];
            while(nums[i] > 0){
                dec = 1;
                vp[i].f += (mapping[nums[i]%10] * dec);
                nums[i] /= 10;
                dec *= 10;
            }
        }
        sort(vp.begin(), vp.end());
        for(i = 0; i < n; i++){
            nums[i] = vp[i].s.s;
        }
        return nums;
    }
};