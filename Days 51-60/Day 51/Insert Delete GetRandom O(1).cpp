/*
Author : Shreeraksha R Aithal
Problem name : Insert Delete GetRandom O(1)
Problem link : https://leetcode.com/problems/insert-delete-getrandom-o1/
Difficulty : Medium
Tags : Array, Design, Hash Table, Math, Randomized
*/

class RandomizedSet {
    vector<int> arr;
    int len;
    map<int,int> mp;
public:
    RandomizedSet() {
        len = 0;
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())    return false;
        mp[val] = len;
        arr.push_back(0);
        arr[len] = val;
        len++;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())    return false;
        if(len == 1){
            mp.erase(val);
            len = 0;
            return true;
        }
        int idx = mp[arr[len-1]] = mp[val];
        mp.erase(val);
        swap(arr[idx], arr[len-1]);
        len--;
        return true;
    }
    
    int getRandom() {
        return arr[rand()%len];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */