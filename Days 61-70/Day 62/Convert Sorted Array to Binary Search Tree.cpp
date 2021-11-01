/*
Author : Shreeraksha R Aithal
Problem name : Convert Sorted Array to Binary Search Tree
Problem link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
Difficulty : Easy
Tags : Array, Binary Search Tree, Binary Tree, Divide and Conquer, Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* arrayNode(vector<int>& nums, int left, int right){
        if(right < left)    return nullptr;
        if(left == right){
            TreeNode* root = new TreeNode(nums[left]);
            return root;
        }
        int mid = (right-left)/2 + left;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = arrayNode(nums, left, mid-1);
        root->right = arrayNode(nums, mid+1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayNode(nums, 0, nums.size()-1);
    }
};