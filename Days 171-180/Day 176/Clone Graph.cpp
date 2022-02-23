/*
Author : Shreeraksha R Aithal
Problem name : Clone Graph
Problem link : https://leetcode.com/problems/clone-graph/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Graph, Hash Table
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)     return nullptr;
        map<Node*, Node*> mp;
        queue<Node*> q;
        Node* head = new Node(node->val);        
        mp[node] = head;
        q.push(node);
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(auto &ptr : node->neighbors){
                if(mp.find(ptr) == mp.end()){
                    Node* root = new Node(ptr->val);
                    mp[ptr] = root;
                    q.push(ptr);
                }
                mp[node]->neighbors.push_back(mp[ptr]);
            }
        }        
        return head;
    }
};