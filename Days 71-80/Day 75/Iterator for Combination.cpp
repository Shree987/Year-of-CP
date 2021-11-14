/*
Author : Shreeraksha R Aithal
Problem name : Iterator for Combination
Problem link : https://leetcode.com/problems/iterator-for-combination/
Difficulty : Medium
Tags : Backtracking, Design, Iterator, String
*/

class CombinationIterator {
public:
    vector<int> arr;
    int n, m;
    string str, chars;
    CombinationIterator(string characters, int combinationLength) {
        n = characters.size();
        m = combinationLength;
        arr = vector<int>(m, 0);
        for(int i = 0; i < m; i++){
            arr[i] = i;
        }
        str = string(m, '0');
        chars = characters;
    }
    
    string next() {
        int i;
        for(i = 0; i < m; i++)      str[i] = chars[arr[i]];
        for(i = m-1; i >= 0; i--){
            if(arr[i] == n-m+i)   continue;
            else{
                arr[i]++;
                for(i = i + 1; i < m; i++)      arr[i] = arr[i-1]+1;
                break;
            }
        }
        if(i < 0)   arr[0] = -1;
        return str;
    }
    
    bool hasNext() {
        return arr[0]>=0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */