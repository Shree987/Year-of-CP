/*
Author : Shreeraksha R Aithal
Problem name : Max Points on a Line
Problem link : https://leetcode.com/problems/max-points-on-a-line/
Difficulty : Hard
Tags : Array, Geometry, Hash Table, Math
*/

class Solution {
    void slope(vector<int>&a, vector<int>&b, pair<int,int>& p){
        p.first = b[0]-a[0], p.second = b[1]-a[1];
        if(p.first == 0)      p.second = 1;
        else if(p.second == 0)     p.first = 1;
        else{
            int gcd = __gcd(abs(p.first), abs(p.second));
            p.first = p.first/gcd;
            p.second = p.second/gcd;
            if(p.first < 0){
                p.first = -p.first;
                p.second = -p.second;
            }
        }
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        pair<int,int> p;
        int count = 1;
        for(int j, i = 0; i < points.size()-1; i++){
            map<pair<int,int>, int> mp;
            for(j = i+1; j < points.size(); j++){
                slope(points[i], points[j], p);
                mp[p]++;
                count = max(count, mp[p]+1);
            }
        }
        return count;
    }
};