/*
Author : Shreeraksha R Aithal
Problem name : Implement Trie (Prefix Tree)
Problem link : https://leetcode.com/problems/implement-trie-prefix-tree/
Difficulty : Medium
Tags : Design, Hash Table, String, Trie
*/

class Node{
public:
    vector<Node*> next;
    bool end;
    Node(){
        next.resize(26);
        for(auto &ptr : next)    ptr = nullptr;
        end = false;
    }
};

class Trie {
public:
    Node *root, *ptr;
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        ptr = root;
        for(auto c : word){
            if(ptr->next[c-'a'] == nullptr){
                ptr->next[c-'a'] = new Node;
            }
            ptr = ptr->next[c-'a'];
        }
        ptr->end = true;
    }
    
    bool search(string word) {
        ptr = root;
        for(auto c : word){
            if(ptr->next[c-'a'] == nullptr){
                return false;
            }
            ptr = ptr->next[c-'a'];
        }
        return ptr->end;
    }
    
    bool startsWith(string prefix) {
        ptr = root;
        for(auto c : prefix){
            if(ptr->next[c-'a'] == nullptr){
                return false;
            }
            ptr = ptr->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */