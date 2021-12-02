/*
Author : Shreeraksha R Aithal
Problem name : Odd Even Linked List
Problem link : https://leetcode.com/problems/odd-even-linked-list/
Difficulty : Medium
Tags : Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || (head->next)->next == nullptr)   return head;
        ListNode *O_head, *E_head, *O_end, *E_end;
        O_head = O_end = head;
        E_head = E_end = head->next;
        head = (head->next)->next;
        O_end->next = E_end->next = nullptr;
        while(true){
            if(head == nullptr)    break;
            O_end->next = head;
            O_end = head;
            head = head->next;
            O_end->next = nullptr;
            if(head == nullptr)    break;
            E_end->next = head;
            E_end = head;
            head = head->next;
            E_end->next = nullptr;
        }
        O_end -> next = E_head;
        return O_head;
    }
};