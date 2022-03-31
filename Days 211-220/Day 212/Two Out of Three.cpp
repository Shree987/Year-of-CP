/*
Author : Shreeraksha R Aithal
Problem name : Two Out of Three
Problem link : https://leetcode.com/problems/two-out-of-three/
Difficulty : Easy
Tags : Array, Hash Table
*/

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int itr1 = 0, itr2 = 0, itr3 = 0, val, count;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        nums3.push_back(INT_MAX);
        vector<int> answer;
        while(true){
            val = min(nums1[itr1], min(nums2[itr2], nums3[itr3]));
            if(val == INT_MAX)      break;
            count = 0;
            if(nums1[itr1] == val)       count++;
            if(nums2[itr2] == val)       count++;
            if(nums3[itr3] == val)       count++;
            if(count >= 2)      answer.push_back(val);
            while(nums1[itr1] == val)        itr1++;
            while(nums2[itr2] == val)        itr2++;
            while(nums3[itr3] == val)        itr3++;
        }
        return answer;
    }
};