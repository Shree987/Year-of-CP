/*
Author : Shreeraksha R Aithal
Problem name : Unique Binary Search Trees II
Problem link : https://leetcode.com/problems/unique-binary-search-trees-ii/
Difficulty : Medium
Tags : Backtracking, Binary Search Tree, Binary Tree, Dynamic Programming, Tree
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
    map<int, vector<TreeNode*>>  mp;
    void dp(int left, int right){
        int hash = left*100 + right;
        if(mp.find(hash) != mp.end())   return ;
        if(left > right){
            mp[hash].push_back(nullptr);
        }
        else if(left == right){
            auto ptr = new TreeNode(left);
            mp[hash].push_back(ptr);
        }
        else{
            dp(left+1, right);
            dp(left, right-1);
            for(auto ptr : mp[hash + 100]){
                auto nptr = new TreeNode(left, nullptr, ptr);
                mp[hash].push_back(nptr);
            }
            for(auto ptr : mp[hash - 1]){
                auto nptr = new TreeNode(right, ptr, nullptr);
                mp[hash].push_back(nptr);
            }
            for(int index = left+1; index < right; index++){
                dp(left, index-1);
                dp(index+1,right);
                auto arr1 = mp[left*100 + index-1], arr2 = mp[(index+1)*100 + right];
                for(auto ptr1 : arr1){
                    for(auto ptr2 : arr2){
                        auto nptr = new TreeNode(index, ptr1, ptr2);
                        mp[hash].push_back(nptr);
                    }
                }
            }
        }
        return ;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        dp(1, n);
        return mp[100+n];
    }
};