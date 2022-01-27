/*
Author : Shreeraksha R Aithal
Problem name : Maximum XOR of Two Numbers in an Array
Problem link : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
Difficulty : Medium
Tags : Array, Bit Manipulation, Hash Table, Trie
*/

class Node{
public:
    Node *_0, *_1;
    bool end;
    
    Node(){
        _0 = _1 = nullptr;
        end = false;
    }    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int answer = 0, i, j, k, res;
        Node *actual, *root = new Node;
        for(auto val : nums){
            k = 31;
            actual = root;
            while(k >= 0){
                if(val & (1 << k)){
                    if(actual->_1 == nullptr)   actual->_1 = new Node;
                    actual = actual->_1;                    
                }
                else{
                    if(actual->_0 == nullptr)   actual->_0 = new Node;
                    actual = actual->_0;
                }
                k--;
            }
            actual->end = true;
            actual = root;
            k = 31;
            res = 0;
            while(k >= 0){
                if(val & (1 << k)){
                    if(actual->_0 == nullptr)   actual = actual->_1;
                    else{
                        actual = actual->_0;
                        res = res | (1 << k);
                    }
                    
                }
                else{
                    if(actual->_1 == nullptr)   actual = actual->_0;
                    else{
                        actual = actual->_1;
                        res = res | (1 << k);
                    }
                }
                k--;
            }
            answer = max(res, answer);
        }
        return answer;
    }
};