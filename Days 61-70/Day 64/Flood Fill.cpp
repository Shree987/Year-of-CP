/*
Author : Shreeraksha R Aithal
Problem name : Flood Fill
Problem link : https://leetcode.com/problems/flood-fill/
Difficulty : Easy
Tags : Array, Breadth-first Search, Depth-first Search, Matrix
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)   return image;
        queue<pair<int, int>> q;
        image[sr][sc] *= -1;
        q.push({sr, sc});
        while(!q.empty()){
            sr = q.front().first;
            sc = q.front().second;
            q.pop();
            if(sr>0 && image[sr-1][sc] == -image[sr][sc]){
                image[sr-1][sc] *= -1;
                q.push({sr-1, sc});
            }
            if(sc>0 && image[sr][sc-1] == -image[sr][sc]){
                image[sr][sc-1] *= -1;
                q.push({sr, sc-1});
            }
            if(sr<image.size()-1 && image[sr+1][sc] == -image[sr][sc]){
                image[sr+1][sc] *= -1;
                q.push({sr+1, sc});
            }
            if(sc<image[0].size() && image[sr][sc+1] == -image[sr][sc]){
                image[sr][sc+1] *= -1;
                q.push({sr, sc+1});
            }
            image[sr][sc] = newColor;
        }
        return image;
    }
};