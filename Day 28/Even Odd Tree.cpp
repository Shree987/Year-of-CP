/*
Author : Shreeraksha R Aithal
Problem name : Even Odd Tree
Problem link : https://leetcode.com/problems/even-odd-tree/
Difficulty : Medium
Tags : Binary Tree, Breadth-first Tree, Tree
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
    bool isEvenOddTree(TreeNode* root) {
        int val, level = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            root = q.front().first;
            if(q.front().second %2 == root->val %2)     return false;
            if(level == q.front().second){
                if(level%2 == 0){
                    if(val >= root->val)    return false;
                    val = root->val;
                }
                else{
                    if(val <= root->val)    return false;
                    val = root->val;
                }                
            }
            else{
                level = q.front().second;
                val = root->val;
            }
            if(root->left != nullptr)   q.push({root->left, q.front().second+1});
            if(root->right != nullptr)   q.push({root->right, q.front().second+1});
            q.pop();
        }
        return true;
    }
};