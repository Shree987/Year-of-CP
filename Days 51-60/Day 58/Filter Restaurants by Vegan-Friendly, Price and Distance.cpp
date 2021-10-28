/*
Author : Shreeraksha R Aithal
Problem name :
Problem link : https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
Difficulty : Medium
Tags : Array, Sorting
*/

int compareVec(vector<int>& v1, vector<int>& v2){
    if(v1[1] != v2[1])      return v1[1]>v2[1];
    return v1[0]>v2[0];
}

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int i, j = 0, n = restaurants.size();
        for(i = 0; i < n; i++){
            if((veganFriendly == 0 || restaurants[i][2] == 1) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                if(i != j){
                    restaurants[j] = restaurants[i];
                }
                j++;
            }
        }
        n = j;
        sort(restaurants.begin(), restaurants.begin()+n, compareVec);
        vector<int> ans(n);
        for(i = 0; i < n; i++){
            ans[i] = restaurants[i][0];
        }
        return ans;
    }
};