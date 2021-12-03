/*
Author : Shreeraksha R Aithal
Problem name : Find the Minimum and Maximum Number of Nodes Between Critical Points
Problem link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        int index = 0, prev = -1, first = -1, pval = head->val, nval;
        head = head->next;
        while(head->next != nullptr){
            nval = head->next->val;
            if((pval<(head->val) && nval<(head->val)) || (pval>(head->val) && nval>(head->val))){
                if(first == -1)     first = index;
                else if(ans[0] == -1 || ans[0] > index-prev)     ans[0] = index-prev;
                prev = index;
            }
            pval = head->val;
            index++;
            head = head->next;
        }
        if(prev != first)      ans[1] = prev-first;
        return ans;
    }
};