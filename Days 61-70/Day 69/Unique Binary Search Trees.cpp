/*
Author : Shreeraksha R Aithal
Problem name : Unique Binary Search Trees
Problem link : https://leetcode.com/problems/unique-binary-search-trees/
Difficulty : Medium
Tags : Binary Search Tree, Binary Tree, Dynamic Programming, Math, Tree
*/

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1)  return 1;
        vector<int> arr(n+1, 0);
        arr[0] = arr[1] = 1;
        for(int num = 2; num<=n; num++){
            for(int itr = 1; itr <= num; itr++){
                arr[num] += arr[itr-1]*arr[num-itr];
            }
        }
        return arr[n];
    }
};