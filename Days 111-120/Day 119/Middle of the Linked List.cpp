/*
Author : Shreeraksha R Aithal
Problem name : Middle of the Linked List
Problem link : https://leetcode.com/problems/middle-of-the-linked-list/
Difficulty : Easy
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
    ListNode* middleNode(ListNode* head) {
        if(head -> next == nullptr)     return head;
        if((head -> next)->next == nullptr){
            return head->next;
        }
        ListNode *slow = head, *fast = head;
        while(slow->next != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr)     break;
            fast = fast->next;
            if(fast == nullptr)     break;
        }
        return slow;
    }
};