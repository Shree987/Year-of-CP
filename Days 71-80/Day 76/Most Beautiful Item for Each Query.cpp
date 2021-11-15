/*
Author : Shreeraksha R Aithal
Problem name : Most Beautiful Item for Each Query
Problem link : https://leetcode.com/problems/most-beautiful-item-for-each-query/
Difficulty : Medium
Tags : Array, Binary Search, Sorting
*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> Items;
        for(int beauty = items[0][1], j, i = 0; i < items.size(); i++){
            j = i+1;
            while(j < items.size() && items[i][0] == items[j][0])   j++;
            j--;
            beauty = max(beauty, items[j][1]);
            Items.push_back(make_pair(items[j][0], beauty));
            i = j;
        }
        for(int left, right, i = 0; i < queries.size(); i++){
            left = 0;
            right = Items.size()-1;
            if(queries[i] > Items[right].first)    queries[i] = Items[right].second;
            else if(queries[i] < Items[0].first)    queries[i] = 0;
            else{
                while(left <= right){
                    if(left == right){
                        queries[i] = Items[left].second;
                        break;
                    }
                    int mid = left + (right-left)/2;
                    if(queries[i] == Items[mid].first){
                        queries[i] = Items[mid].second;
                        break;
                    }
                    else if(queries[i] < Items[mid].first){
                        right = mid-1;
                    }
                    else if(queries[i] >= Items[mid+1].first){
                        left = mid+1;
                    }
                    else{
                        queries[i] = Items[mid].second;
                        break;
                    }
                }
            }
        }
        return queries;
    }
};