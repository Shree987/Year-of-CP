/*
Author : Shreeraksha R Aithal
Problem name : Remove Linked List Elements
Problem link : https://leetcode.com/problems/remove-linked-list-elements/
Difficulty : Easy
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val)      head = head->next;
        if(head == nullptr)         return nullptr;
        ListNode *root = head;
        while(root->next != nullptr){
            if((root->next)->val  == val){
                root->next = (root->next)->next;
            }
            else{
                root = root->next;
            }
        }
        return head;
    }
};