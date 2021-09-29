/*
Author : Shreeraksha R Aithal
Problem name : Split Linked List in Parts
Problem link : https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        int n = 0, left, nk, m, idx = 0;
        ListNode *root = head, *ptr;
        while(root != nullptr){
            n++;
            root = root->next;
        }
        m = n%k;
        left = n/k;
        while(head != nullptr){
            res[idx] = head;
            if(m > 0){
                m--;
                nk = left;
            }
            else    nk = left-1;
            while(nk > 0){
                head = head->next;
                nk--;
            }
            ptr = head->next;
            head->next = nullptr;
            head = ptr;
            idx++;
        }
        return res;
    }
};