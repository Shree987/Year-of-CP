/*
Author : Shreeraksha R Aithal
Problem name : Rotate List
Problem link : https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)        return head;
        ListNode *root = head, *end;
        int len = 0;
        while(root != nullptr){
            len++;
            end = root;
            root = root->next;
        }
        k = k%len;
        if(k == 0)  return head;
        k = len - k;
        root = head;
        while(k > 1){
            root = root->next;
            k--;
        }
        end->next = head;
        end = root;
        root = root->next;
        end->next = nullptr;
        return root;
    }
};