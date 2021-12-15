/*
Author : Shreeraksha R Aithal
Problem name : Insertion Sort List
Problem link : https://leetcode.com/problems/insertion-sort-list/
Difficulty : Medium
Tags : Linked List, Sorting
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *root = head, *ptr = root;
        while(ptr!=nullptr){
            int val = ptr->val;
            root = head;
            while(root != ptr){
                if(root->val > val){
                    swap(root->val, val);
                }
                root = root->next;
            }
            ptr->val = val;
            ptr = ptr->next;
        }
        return head;
    }
};