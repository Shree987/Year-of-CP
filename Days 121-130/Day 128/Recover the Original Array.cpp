/*
Author : Shreeraksha R Aithal
Problem name : Recover the Original Array
Problem link : https://leetcode.com/problems/recover-the-original-array/
Difficulty : Hard
Tags : Array, Enumeration, Hash Table, Sorting
*/

class Solution {
    void cl(vector<int>& nums, map<int, int>& mp){
        mp.clear();
        for(auto k : nums)      mp[k]++;
    }
public:
    vector<int> recoverArray(vector<int>& nums) {
        map<int, int> mp;
        cl(nums, mp);
        sort(nums.begin(), nums.end());
        int k = -1, n = nums.size()/2;
        for(int j, i = 1; i < 2*n; i++){
            k = nums[i] - nums[0];
            if(k%2 == 1 || k == 0)    continue;
            for(j = 0; j < 2*n; j++){
                if(mp[nums[j]] > 0){
                    if(mp[nums[j]+k] > 0){
                        mp[nums[j]]--;
                        mp[nums[j]+k]--;
                    }
                    else    break;
                }
            }
            cl(nums, mp);
            if(j == 2*n){              
                break;
            }
        }
        k /= 2;
        vector<int> arr;
        for(int j = 0, i = 0; j < 2*n; j++){
            if(mp[nums[j]] > 0){
                mp[nums[j]]--;                
                mp[nums[j] + k + k]--;
                arr.push_back(nums[j]+k);
            }
        }
        return arr;
    }
};