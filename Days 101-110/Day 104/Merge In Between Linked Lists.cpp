/*
Author : Shreeraksha R Aithal
Problem name : Merge In Between Linked Lists
Problem link : https://leetcode.com/problems/merge-in-between-linked-lists/
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* root = new ListNode;
        root->next = list1;
        list1 = root;
        int index = 0;
        while(index <= a-1){
            list1 = list1->next;
            index++;
        }
        ListNode* ptr = list1->next;
        list1->next = list2;
        while(list2->next != nullptr){
            list2 = list2->next;
        }
        index = a-1;
        while(index <= b-1){            
            ptr = ptr->next;
            index++;
        }
        list2->next = ptr;
        return root->next;
    }
};