/*
Author : Shreeraksha R Aithal
Problem name : Largest Triangle Area
Problem link : https://leetcode.com/problems/largest-triangle-area/
Difficulty : Easy
Tags : Array, Geometry, Math
*/

class Solution {
    int Area(vector<int> &A, vector<int> &B, vector<int> &C){
        return abs(A[0]*(B[1]-C[1]) + B[0]*(C[1]-A[1]) + C[0]*(A[1]-B[1]));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                for(int k = j+1; k < points.size(); k++){
                    ans = max(ans, Area(points[i], points[j], points[k]));
                }
            }
        }
        return ((double) ans)/2;
    }
};