/*
Author : Shreeraksha R Aithal
Problem name : Flipping an Image
Problem link : https://leetcode.com/problems/flipping-an-image/
Difficulty : Easy
Tags : Array, Matrix, Simulation, Two Pointers
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++){
            for(int j = 0; j+j < image[0].size(); j++){
                if(j+j == image[0].size()-1){
                    image[i][j] = 1- image[i][j];
                }
                else{
                    swap(image[i][j], image[i][image[0].size()-j-1]);
                    image[i][j] = 1 - image[i][j];
                    image[i][image[0].size()-j-1] = 1 - image[i][image[0].size()-j-1];
                }
            }
        }
        return image;
    }
};