/*
Author : Shreeraksha R Aithal
Problem name : Maximum Twin Sum of a Linked List
Problem link : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
Difficulty : Medium
Tags : Linked List, Stack, Two Pointers
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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* root = head;
        int i, Max = -1, n = 0;
        while(head != nullptr){
            n++;
            st.push(head->val);
            head = head->next;
        }
        n /= 2;
        for(i = 0; i < n; i++){
            root->val += st.top();
            Max = max(Max, root->val);
            st.pop();
            root = root->next;
        }
        return Max;
    }
};