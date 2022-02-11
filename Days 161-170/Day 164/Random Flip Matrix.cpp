/*
Author : Shreeraksha R Aithal
Problem name : Random Flip Matrix
Problem link : https://leetcode.com/problems/random-flip-matrix/
Difficulty : Medium
Tags : Hash Table, Math, Reservoir Sampling, Randomized
*/

class Solution {
public:
    int m, n, x, y;
    set<pair<int,int>> sp;
    Solution(int m, int n) {
        srand(time(0));
        this->m = m;
        this->n = n;
        x = m-1;
        y = n-1;
    }
    
    vector<int> flip() {
        vector<int> ans(2);
        int num = rand()%(n*m);
        int x_ = num/n, y_ = num%n;
        while(true){
            if(sp.find(make_pair(x_, y_)) == sp.end()){
                break;
            }
            x_ = x;
            y_ = y;
            if(y == 0){
                y = n-1;
                x--;
            }
            else{
                y--;
            }
        }
        if(x_ == -1)    reset();
        sp.insert(make_pair(x_, y_));
        ans[0] = x_;
        ans[1] = y_;
        return ans;
    }
    
    void reset() {
        sp.clear();
        x = m-1;
        y = n-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */