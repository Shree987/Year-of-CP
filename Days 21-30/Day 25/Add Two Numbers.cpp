/*
Author : Shreeraksha R Aithal
Problem name : Add Two Numbers
Problem link : https://leetcode.com/problems/add-two-numbers/
Difficulty : Medium
Tags : Linked List, Math, Recursion
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *root, *ptr;
        root = new ListNode();
        ptr = root;
        while(carry > 0 || l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                carry += l2->val;
                l2 = l2->next;
            }
            ptr->next = new ListNode(carry);
            ptr = ptr->next;
            carry = ptr->val / 10;
            ptr->val %= 10;
        }
        return root->next;
    }
};