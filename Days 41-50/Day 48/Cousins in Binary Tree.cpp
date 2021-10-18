/*
Author : Shreeraksha R Aithal
Problem name : Cousins in Binary Tree
Problem link : https://leetcode.com/problems/cousins-in-binary-tree/
Difficulty : Easy
Tags : Binary Tree, Breadth-first Tree, Depth-first Tree, Tree
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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)    return false;
        pair<int,int> X = {-1,-1}, Y = {-1,-1};
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while(!q.empty() && (X.first == -1 || Y.first == -1)){
            root = q.front().first;
            int d = q.front().second;
            q.pop();
            if(X.first > -1 && X.first < d)     return false;
            if(Y.first > -1 && Y.first < d)     return false;
            if(root->left != nullptr){
                if(root->left->val == x){
                    X = {d+1, root->val};
                }
                if(root->left->val == y){
                    Y = {d+1, root->val};
                }
                q.push({root->left, d+1});
            }
            if(root->right != nullptr){
                if(root->right->val == x){
                    X = {d+1, root->val};
                }
                if(root->right->val == y){
                    Y = {d+1, root->val};
                }
                q.push({root->right, d+1});
            }
        }
        return (X.first == Y.first && X.second != Y.second);
    }
};