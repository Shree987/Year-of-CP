/*
Author : Shreeraksha R Aithal
Problem name : Merge Two Sorted Lists
Problem link : https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *root, *head;
        head = root = new ListNode();
        while(list1 != nullptr && list2 != nullptr){
            if((list1->val) < (list2->val)){
                head->next = list1;
                head = list1;
                list1 = list1->next;
            }
            else{
                head->next = list2;
                head = list2;
                list2 = list2->next;
            }
        }
        if(list1 == nullptr)        head->next = list2;
        else    head->next = list1;
        return root->next;
    }
};