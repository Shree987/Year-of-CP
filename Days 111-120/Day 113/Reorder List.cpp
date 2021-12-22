/*
Author : Shreeraksha R Aithal
Problem name : Reorder List
Problem link : https://leetcode.com/problems/reorder-list/
Difficulty : Medium
Tags : Linked List, Recursion, Stack, Two Pointers
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
    void reorderList(ListNode* head) {
        int count = 0, total = 0;
        stack<ListNode*> st;
        ListNode* root = head;
        while(head != nullptr){
            total++;
            st.push(head);
            head = head->next;
        }
        head = root;
        while(count < total){
            if(count+1 == total)    break;
            auto ptr = st.top();
            st.pop();
            ptr->next = head->next;
            head->next = ptr;
            head = ptr->next;
            count+=2;
        }
        head->next = nullptr;
    }
};