/*
Author : Shreeraksha R Aithal
Problem name : Finding Pairs With a Certain Sum
Problem link : https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
Difficulty : Medium
Tags : Array, Design, Hash Table
*/

class FindSumPairs {
public:
    map<int, int> mp1, mp2;
    vector<int> num;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto &k : nums1)    mp1[k]++;
        for(auto &k : nums2)    mp2[k]++;
        num = nums2;
    }
    
    void add(int index, int val) {
        if(mp2[num[index]] == 0)        mp2.erase(num[index]);
        else    mp2[num[index]]--;
        num[index] += val;
        mp2[num[index]]++;
    }
    
    int count(int tot) {
        int sum = 0;
        for(auto p : mp2){
            sum += p.second * (mp1[tot - p.first]);
        }
        return sum;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */