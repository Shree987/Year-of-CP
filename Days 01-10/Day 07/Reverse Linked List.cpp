/*
Author : Shreeraksha R Aithal
Problem name : Reverse Linked List
Problem link : https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* root;
public:
    ListNode* RevList(ListNode* head) {
        if(head->next == nullptr){
            root = head;
        }
        else{            
            RevList(head->next) -> next = head;
        }       
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(head ==  nullptr || head->next == nullptr)       return head;
        RevList(head->next)->next = head;
        head->next = nullptr;
        return root;
    }
};