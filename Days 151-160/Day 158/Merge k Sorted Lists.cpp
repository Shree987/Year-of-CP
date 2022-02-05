/*
Author : Shreeraksha R Aithal
Problem name : Merge k Sorted Lists
Problem link : https://leetcode.com/problems/merge-k-sorted-lists/
Difficulty : Hard
Tags : Divide and Conquer, Heap (Priority Queue), Linked List
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

auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        ListNode *head, *root = new ListNode;
        head = root;
        for(auto ptr : lists){
            if(ptr != nullptr)      pq.push(ptr);
        }
        while(!pq.empty()){
            auto ptr = pq.top();
            pq.pop();
            root->next = ptr;
            root = ptr;
            if(ptr -> next != nullptr)      pq.push(ptr->next);
        }
        return head->next;
    }
};