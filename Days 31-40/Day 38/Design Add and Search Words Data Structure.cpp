/*
Author : Shreeraksha R Aithal
Problem name : Design Add and Search Words Data Structure
Problem link : https://leetcode.com/problems/design-add-and-search-words-data-structure/
Difficulty : Medium
Tags : Design, Depth-first Search, String, Trie
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

class WordDictionary {
public:
    Node *root, *ptr;
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
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
        int i, n = word.size();
        queue<pair<Node*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            i = Q.front().second;
            ptr = Q.front().first;
            Q.pop();
            if(i == n){
                if(ptr -> end)      return true;                
            }
            else{
                if(word[i] == '.'){
                    for(auto child : ptr->next){
                        if(child != nullptr)    Q.push({child, i+1});
                    }
                }
                else{
                    if(ptr->next[word[i]-'a'] != nullptr)
                        Q.push({ptr->next[word[i]-'a'], i+1});
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */