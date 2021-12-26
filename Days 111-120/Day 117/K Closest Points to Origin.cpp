/*
Author : Shreeraksha R Aithal
Problem name : K Closest Points to Origin
Problem link : https://leetcode.com/problems/k-closest-points-to-origin/
Difficulty : Medium
Tags : Array, Divide and Conquer, Geometry, Heap (Priority Queue),  Math, Quickselect, Sorting
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> vvp;
        for(auto p : points){
            vvp.push_back({(p[0]*p[0] + p[1]*p[1]), p});
        }
        sort(vvp.begin(), vvp.end());
        points.resize(k);
        for(int i = 0; i < k; i++)    points[i] = vvp[i].second;
        return points;
    }
};