/*
Author : Shreeraksha R Aithal
Problem name : Linked List Cycle
Problem link : https://leetcode.com/problems/linked-list-cycle/
Difficulty : Easy
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)    return false;
        if(head -> next == head)       return true;
        ListNode *slow, *fast;
        slow = fast = head;
        do{
            slow = slow->next;
            fast = fast->next;
            if(slow == nullptr || fast == nullptr)     return false;
            fast = fast->next;
            if(fast == nullptr)     return false;
        }while(slow != fast);
        return true;
    }
};