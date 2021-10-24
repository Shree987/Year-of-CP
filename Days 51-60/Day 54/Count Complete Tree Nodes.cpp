/*
Author : Shreeraksha R Aithal
Problem name : Count Complete Tree Nodes
Problem link : https://leetcode.com/problems/count-complete-tree-nodes/
Difficulty : Medium
Tags : Binary Search, Binary Tree, Depth-first Search, Tree
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
    int count, H;
    bool end;
    void dfs(TreeNode* root, int h){
        if(end)     return ;
        if(h == H-1){
            if(root->left == nullptr){
                count-=2;
                return ;
            }
            end = true;
            if(root->right == nullptr){
                count--;
            }
            return ;
        }
        else{
            dfs(root->right, h+1);
            if(end)     return ;
            dfs(root->left, h+1);
        }
    }
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)     return 0;
        count = H = 0;
        end = false;
        auto ptr = root;
        while(ptr != nullptr){
            H++;
            ptr = ptr->left;
        }
        if(H <= 1)      return H;
        count = (1 << H) - 1;
        dfs(root, 1);
        return count;
    }
};