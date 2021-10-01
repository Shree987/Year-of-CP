/*
Author : Shreeraksha R Aithal
Problem name : Find First and Last Position of Element in Sorted Array
Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Difficulty : Medium
Tags : Array, Binary Search
*/

class Solution {
    int findIndex(vector<int> &v, int &left, int &right, int &target, bool findLeft){
        int mid;
        while(left < right){
            cout<<target<<" : "<<left<<" "<<right<<"\n";
            if(left+1 == right){
                if(findLeft){
                    if(v[left] == target)   return left;
                    if(v[right] == target)   return right;
                }
                else{
                    if(v[right] == target)   return right;
                    if(v[left] == target)   return left;                    
                }
                return -1;
            }
            mid = (left + right)/2;
            if(v[mid] == target){
                if(findLeft)    right = mid;
                else    left = mid;
            }
            else if(v[mid] > target)    right = mid-1;    
            else if(v[mid] < target)    left = mid+1;
        }
        if(v[left] == target)    return left;
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int i, j, n = nums.size()-1;
        if(n == -1 || nums[0] > target || target > nums[n])    return ans;
        if(n == 0){
            if(nums[0] == target)   ans[0] = ans[1] = 0;
            return ans;
        }
        i = 0;
        j = n;
        if(nums[0] == target){
            ans[0] = 0;
            if(nums[ans[0]+1] != target){
                ans[1] = ans[0];
                return ans;
            }
            i = 0;
            j = n;
            ans[1] = findIndex(nums, i, j, target, false);
        }
        else if(nums[n] == target){
            ans[1] = n;
            if(nums[ans[1]-1] != target){
                ans[0] = ans[1];
                return ans;
            }
            i = 0;
            j = n;
            ans[0] = findIndex(nums, i, j, target, true);
        }
        else{
            ans[0] = findIndex(nums, i, j, target, true);
            if(ans[0] == -1)    return ans;
            if(nums[ans[0]+1] != target){
                ans[1] = ans[0];
                return ans;
            }
            i = ans[0];
            j = n;
            ans[1] = findIndex(nums, i, j, target, false);
        }
        return ans;
    }
};