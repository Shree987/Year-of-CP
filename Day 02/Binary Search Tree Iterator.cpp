/*
Author : Shreeraksha R Aithal
Problem name : Binary Search Tree Iterator
Problem link : https://leetcode.com/problems/binary-search-tree-iterator/
Difficulty : Medium
Tags : Binary Search Tree, Binary Tree, Design, Iterator, Stack, Tree
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
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        st.push(root);
    }
    
    int next() {
        while(!st.empty()){
            if(st.top() == nullptr){
                st.pop();
                continue;
            }
            if(st.top()->left != nullptr){
                TreeNode* ptr = st.top();
                st.pop();
                st.push(ptr->right);
                auto nptr = new TreeNode(ptr->val);
                st.push(nptr);
                st.push(ptr->left);
            }
            else{
                int val = st.top()->val;
                if(st.top()->right != nullptr){
                    auto ptr = st.top()->right;
                    st.pop();
                    st.push(ptr);
                }
                else    st.pop();
                return val;
            }
        }
        return -1;
    }
    
    bool hasNext() {
        while(!st.empty() && st.top() == nullptr)   st.pop();
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */