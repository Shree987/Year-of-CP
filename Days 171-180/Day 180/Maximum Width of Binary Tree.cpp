/*
Author : Shreeraksha R Aithal
Problem name : Maximum Width of Binary Tree
Problem link : https://leetcode.com/problems/maximum-width-of-binary-tree/
Difficulty : Medium
Tags : Binary Tree, Breadth-first Search, Depth-first Search, Tree
*/

#define ull unsigned long long
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ull>> q;
        bool start = true;
        ull answer = 1, level = -1;
        q.push({root, 0});
        q.push({nullptr, -1});
        while(q.size() > 1){
            root = q.front().first;
            ull val = q.front().second;
            q.pop();
            if(root == nullptr){
                if(q.empty() == 1)   break;
                q.push({nullptr, -1});
                level = 0;
                start = true;
            }
            else{
                if(root->left != nullptr)           q.push({root->left, val*2});
                if(root->right != nullptr)          q.push({root->right, 1 + val*2});
                
                if(start){
                    level = val;
                    start = false;
                }
                else{
                    answer = max(answer, val-level+1);
                }
            }
        }
        return answer;
    }
};