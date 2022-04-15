/*
Author : Shreeraksha R Aithal
Problem name : Most Frequent Subtree Sum
Problem link : https://leetcode.com/problems/most-frequent-subtree-sum/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Hash Table, Tree
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
    int SubTreeSum(TreeNode* root, map<int, int> &sumMap){
        if(root == nullptr)     return 0;
        int sum = root->val + SubTreeSum(root->left, sumMap) + SubTreeSum(root->right, sumMap);
        sumMap[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> sumMap;
        SubTreeSum(root, sumMap);
        int Max = 0;
        vector<int> res;
        for(auto p : sumMap){
            if(p.second > Max){
                Max = p.second;
                res.clear();
                res.push_back(p.first);
            }
            else if(p.second == Max){
                res.push_back(p.first);
            }
        }
        return res;
    }
    
};