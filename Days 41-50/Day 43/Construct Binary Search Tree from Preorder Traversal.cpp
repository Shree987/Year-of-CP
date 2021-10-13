/*
Author : Shreeraksha R Aithal
Problem name : Construct Binary Search Tree from Preorder Traversal
Problem link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
Difficulty : Medium
Tags : Array, Binary Search Tree, Binary Tree, Monotonic Stack, Stack, Tree
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
public:
    TreeNode* NodeBuild(vector<int>& preorder, int left, int right){
        if(left > right)    return nullptr;
        auto root = new TreeNode(preorder[left]);
        if(left == right)   return root;
        if(preorder[right] < preorder[left]){
            root->left = NodeBuild(preorder, left+1, right);
            return root;
        }
        if(preorder[left+1] > preorder[left]){
            root->right = NodeBuild(preorder, left+1, right);
            return root;            
        }
        int mid = left+1;
        while(preorder[mid] < preorder[left])   mid++;
        root->left = NodeBuild(preorder, left+1, mid-1);
        root->right = NodeBuild(preorder, mid, right);
        return root;
    }
        
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return NodeBuild(preorder, 0, preorder.size()-1);
    }
};