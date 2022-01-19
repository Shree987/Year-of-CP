/*
Author : Shreeraksha R Aithal
Problem name : Linked List Cycle II
Problem link : https://leetcode.com/problems/linked-list-cycle-ii/
Difficulty : Medium
Tags : Hash Table, Linked List, Two Pointers
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)        return nullptr;
        ListNode *fast = head, *slow = head;
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr || slow == nullptr)      return nullptr;
            fast = fast->next;
            if(fast == nullptr)     return nullptr;
        }while(fast != slow);
        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};