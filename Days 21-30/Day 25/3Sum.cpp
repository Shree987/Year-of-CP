/*
Author : Shreeraksha R Aithal
Problem name : 3Sum
Problem link : https://leetcode.com/problems/3sum/
Difficulty : Medium
Tags : Array, Sorting, Two Pointers
*/
    
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int> > answer;
            vector<int> res(3);
            sort(nums.begin(), nums.end());
            int i, j, k, m, n = nums.size();
            for(i = 0; i < n; ){
                j = i+1;
                k = n-1;
                while(j<k){
                    if(nums[j] + nums[k] + nums[i] == 0){
                        answer.push_back({nums[i], nums[j], nums[k]});
                        m = j;
                        while(j<=k && nums[m] == nums[j])   j++;
                        k--;
                    }
                    else if(nums[j] + nums[k] + nums[i] > 0){
                        k--;
                    }
                    else    j++;
                }
                m = i;
                while(i<n && nums[i] == nums[m])    i++;            
            }
            return answer;
        }
    };