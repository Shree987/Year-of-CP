/*
Author : Shreeraksha R Aithal
Problem name : Convert Binary Number in a Linked List to Integer
Problem link : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
Difficulty : Easy
Tags : Linked List, Math
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
    int getDecimalValue(ListNode* head) {
        int num = 0;
        while(head != nullptr){
            num = num*2 + head->val;
            head = head->next;
        }
        return num;
    }
};