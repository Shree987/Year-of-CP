/*
Author : Shreeraksha R Aithal
Problem name : All Elements in Two Binary Search Trees
Problem link : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
Difficulty : Medium
Tags : Binary Search Tree, Binary Tree, Depth-first Search, Sorting, Tree
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
    queue<int> q;
    vector<int> answer;
    void dfs(TreeNode* root, bool first){
        if(root == nullptr)     return ;
        dfs(root->left, first);
        if(first){
            q.push(root->val);
        }
        else{
            while(!q.empty() && q.front() <= root->val){
                answer.push_back(q.front());
                q.pop();
            }
            answer.push_back(root->val);
        }
        dfs(root->right, first);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1, true);
        dfs(root2, false);
        while(!q.empty()){
            answer.push_back(q.front());
            q.pop();
        }
        return answer;
    }
};