/*
Author : Shreeraksha R Aithal
Problem name : Swapping Nodes in a Linked List
Problem link : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
Difficulty : Medium
Tags : Linked List, Two Pointers
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0, idx = 0;
        ListNode *root = head, *kNode = nullptr, *k_Node = nullptr;
        while(root != nullptr){
            len++;
            root = root->next;
        }
        if(k+k-1 == len)  return head;
        if(k+k > len)    k = len-k+1;
        idx = 0;
        root = head;
        while(root != nullptr){
            idx++;
            if(idx == k)    kNode = root;
            else if(idx == len-k+1)   k_Node = root;
            root = root->next;
        }
        swap(kNode->val, k_Node->val);
        return head;
    }
};