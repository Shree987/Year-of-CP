/*
Author : Shreeraksha R Aithal
Problem name : Linked List Random Node
Problem link : https://leetcode.com/problems/linked-list-random-node/
Difficulty : Medium
Tags : Linked List, Math, Reservoir Sampling, Randomized
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
    vector<ListNode*> list;
public:
    Solution(ListNode* head) {
        srand(time(0));
        while(head != nullptr){
            list.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        return (list[rand()%list.size()])->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */