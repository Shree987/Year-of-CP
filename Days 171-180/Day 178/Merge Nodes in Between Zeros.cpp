/*
Author : Shreeraksha R Aithal
Problem name : Merge Nodes in Between Zeros
Problem link : https://leetcode.com/problems/merge-nodes-in-between-zeros/
Difficulty : Medium
Tags : Linked List, Simulation
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *root = head, *ptr = head;
        head = head->next;
        while(head != nullptr){
            int sum = 0;
            while(head->val != 0){
                sum += head->val;
                head = head->next;
            }
            ptr = ptr->next;
            ptr->val = sum;
            head = head->next;
        }
        ptr->next = nullptr;
        return root->next;
    }
};