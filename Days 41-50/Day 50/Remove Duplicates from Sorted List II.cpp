/*
Author : Shreeraksha R Aithal
Problem name : Remove Duplicates from Sorted List II
Problem link : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = new ListNode;
        root->next = head;
        ListNode* ptr;
        head = root;
        while(head != nullptr){
            if(head->next == nullptr || head->next->next == nullptr)    break;
            ptr = head->next;
            while(ptr->next != nullptr && ptr->next->val == head->next->val)  ptr = ptr->next;
            if(ptr == head->next){
                head = ptr;
            }
            else{
                head->next = ptr->next;
            }
        }
        return root->next;
    }
};