/*
Author : Shreeraksha R Aithal
Problem name : Can Place Flowers
Problem link : https://leetcode.com/problems/can-place-flowers/
Difficulty : Easy
Tags : Array, Greedy
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = -2, i = 0, m = flowerbed.size();
        while(i<m && n>0){
            if(flowerbed[i] == 1){
                n -= max(0, (i-prev-2)/2);
                prev = i;
            }
            i++;
        }
        n -= max(0, (m-prev-1)/2);
        return (n <= 0);
    }
};