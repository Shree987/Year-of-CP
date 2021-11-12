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
        ListNode* root = new ListNode;
        root->next = head;
        head = root;
        while(head->next != nullptr){
            if(head->next->val == val)      head->next = (head->next)->next;
            else    head = head->next;
        }
        return root->next;
    }    
};