/*
Author : Shreeraksha R Aithal
Problem name : Add One Row to Tree
Problem link : https://leetcode.com/problems/add-one-row-to-tree/
Difficulty : Medium
Tags : Binary Tree, Breadth-first Search, Depth-first Search, Tree
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
    void Dfs(TreeNode* ptr, int &depth, int currDepth, int &val){
        if(ptr == nullptr || currDepth >= depth)   return ;
        if(currDepth == depth-1){
            TreeNode* ptrL = new TreeNode(val, ptr->left, nullptr);
            TreeNode* ptrR = new TreeNode(val, nullptr, ptr->right);
            ptr->left = ptrL;
            ptr->right = ptrR;
            return ;
        }
        else{
            if(ptr->left != nullptr)    Dfs(ptr->left, depth, currDepth+1, val);
            if(ptr->right != nullptr)    Dfs(ptr->right, depth, currDepth+1, val);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* head = new TreeNode(val, root, nullptr);
            return head;
        }
        Dfs(root, depth, 1, val);
        return root;
    }
};