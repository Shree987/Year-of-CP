/*
Author : Shreeraksha R Aithal
Problem name : Maximum Level Sum of a Binary Tree
Problem link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
Difficulty : Medium
Tags : Binary Tree, Breadth-first Search, Tree
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
    int maxLevelSum(TreeNode* root) {        
        int ans = root->val, sum = 0, res = 1, level = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            if(q.front() == nullptr){
                if(sum > ans){
                    ans = sum;
                    res = level;
                }
                sum = 0;
                if(q.size() > 1)     q.push(nullptr);
                level++;
            }
            else{
                sum += q.front()->val;
                if(q.front()->left != nullptr){
                    q.push(q.front()->left);
                }
                if(q.front()->right != nullptr){
                    q.push(q.front()->right);
                }
            }
            q.pop();
        }
        return res;
    }
};