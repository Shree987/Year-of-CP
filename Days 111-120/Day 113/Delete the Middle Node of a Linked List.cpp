/*
Author : Shreeraksha R Aithal
Problem name : Delete the Middle Node of a Linked List
Problem link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == nullptr)     return nullptr;
        if((head -> next)->next == nullptr){
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while(slow->next != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr)     break;
            fast = fast->next;
            if(fast == nullptr)     break;
        }
        slow->val = (slow->next)->val;
        slow->next = (slow->next)->next;
        return head;
    }
};