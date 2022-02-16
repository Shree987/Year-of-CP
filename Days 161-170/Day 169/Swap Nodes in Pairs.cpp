/*
Author : Shreeraksha R Aithal
Problem name : Swap Nodes in Pairs
Problem link : https://leetcode.com/problems/swap-nodes-in-pairs/
Difficulty : Medium
Tags : Linked List, Recursion
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* root = head;
        while(root != nullptr && root->next != nullptr){
            swap(root->val, (root->next)->val);
            root = (root->next)->next;
        }
        return head;
    }
};