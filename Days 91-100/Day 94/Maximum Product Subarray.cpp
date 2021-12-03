/*
Author : Shreeraksha R Aithal
Problem name : Maximum Product Subarray
Problem link : https://leetcode.com/problems/maximum-product-subarray/
Difficulty : Medium
Tags : Array, Dynamic Programming
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long ans = nums[0], prod;
        int i = 0, n = nums.size(), count, j;
        while(i<n){
            if(nums[i] == 0){
                ans = max(0L, ans);
            }
            else{
                prod = 1;
                count = 0;
                j = i;
                while(i<n && nums[i] != 0){
                    if(nums[i] < 0)     count++;
                    prod *= nums[i];
                    i++;
                }
                i--;
                ans = max(ans, prod);
                if(count % 2 == 1){
                    if(i == j){
                        ans = max(ans, nums[i] + 0L);
                    }
                    else{
                        long prod2 = prod;
                        for(int k = j; k <= i; k++){
                            prod2 /= nums[k];
                            if(nums[k] < 0)     break;
                        }
                        ans = max(ans, prod2);
                        prod2 = prod;
                        for(int k = i; k >= j; k--){
                            prod2 /= nums[k];
                            if(nums[k] < 0)     break;
                        }
                        ans = max(ans, prod2);
                    }
                }
            }
            i++;
        }
        return ans;
    }
};