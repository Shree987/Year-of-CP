/*
Author : Shreeraksha R Aithal
Problem name : Fancy Sequence
Problem link : https://leetcode.com/problems/fancy-sequence/
Difficulty : Hard
Tags : Design, Math, Segment Tree
*/

#define f first 
#define s second
#define M 1000000007
#define ll long long
#define pil pair<ll, ll>

class Fancy {
    vector<pil> arr;
    vector<pair<ll, pil>> opr;
    int T, len;
    
    unsigned long modPow(unsigned long x, int y) {
        unsigned long tot = 1, p = x;
        for (; y; y >>= 1) {
            if (y & 1)
                tot = (tot * p) % M;
            p = (p * p) % M;
        }
        return tot;
    }
    
    int binary_search(int t){
        int start = 1, end = len-1;
        if(opr[end].f < t)      return -1;
        while(start < end){
            int mid = start + (end-start)/2;
            if(opr[mid].f > t)      end = mid;
            else    start = mid+1;
        }
        return end;
    }
    
public:
    Fancy() {
        T = 0;
        len = 1;
        opr.push_back({0, {0, 1}});
    }
    
    void append(int val) {
        T++;
        arr.push_back({T, val});
    }
    
    void addAll(int inc) {
        T++;
        opr.push_back({T, {(opr[len-1].s.f + inc)%M, (opr[len-1].s.s)%M }});
        len++;
    }
    
    void multAll(int m) {
        if(m == 1)      return ;
        T++;
        opr.push_back({T, {(opr[len-1].s.f * m)%M, (opr[len-1].s.s * m)%M }});
        len++;
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size())   return -1;
        int t = arr[idx].f;
        long long val = arr[idx].s, m1, m2, m;
        int index = binary_search(t);
        if(index == -1)     return val;
        m1 = opr[len-1].s.s;
        m2 = modPow(opr[index-1].s.s, M-2);
        m = (m1 * m2)%M;
        val = (val * m)%M;
        val = (val + (opr[len-1].s.f - (opr[index-1].s.f * m))%M + M)%M;
        return (val+M)%M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */