/*
Author : Shreeraksha R Aithal
Problem name : Fraction Addition and Subtraction
Problem link : https://leetcode.com/problems/fraction-addition-and-subtraction/
Difficulty : Medium
Tags : Math, Simulation, String
*/

#define ll long
class Solution {
public:
    string fractionAddition(string expression) {
        ll i = 0, num, den, gcd, n = expression.size();
        pair<ll,ll> p = {-1, -1};
        bool plus = true;
        while(i < n){
            if(expression[i] == '+'){
                plus = true;
                i++;
            }
            else if(expression[i] == '-'){
                plus = false;
                i++;
            }
            else{
                num = 0;
                while(isdigit(expression[i])){
                    num = num*10 + (expression[i]-'0');
                    i++;
                }
                i++;                
                den = 0;
                while(isdigit(expression[i])){
                    den = den*10 + (expression[i]-'0');
                    i++;
                }
                if(!plus){
                    num *= -1;
                }
                
                if(p.second == -1)     p = {num, den};
                else{
                    gcd = __gcd(den, p.second);
                    p.first = (p.first * (den / gcd)) + (num * (p.second / gcd));
                    p.second *= den/gcd;
                }
                if(p.first == 0)    p.second = 1;
                else{
                    gcd = __gcd(p.second, abs(p.first));
                    p.first /= gcd;
                    p.second /= gcd;
                }
                plus = true;
            }            
        }
        expression = "";
        if(p.first < 0){
            expression = "-";
            p.first *= -1;
        }       
        return expression + to_string(p.first) + "/" + to_string(p.second);
    }
};