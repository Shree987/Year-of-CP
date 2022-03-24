/*
Author : Shreeraksha R Aithal
Problem name : Validate IP Address
Problem link : https://leetcode.com/problems/validate-ip-address/
Difficulty : Hard
Tags : String
*/

class Solution {
public:
    string validIPAddress(string queryIP) {
        int TypeFlag = 0, count = 0, left, right;
        for(auto &ch : queryIP){
            if(ch == ':'){
                if(TypeFlag == 0 || TypeFlag == 6){
                    TypeFlag = 6;
                    count++;
                }
                else{
                    return "Neither";
                }
            }
            else if(ch == '.'){
                if(TypeFlag == 0 || TypeFlag == 4){
                    TypeFlag = 4;
                    count++;
                }
                else{
                    return "Neither";
                }
            }
            else if(!isalnum(ch))       return "Neither";
        }
        if(TypeFlag == 4 && count == 3){
            // IPv4
            left = 0;
            while(left < queryIP.size()){
                if(queryIP[left] == '.')        return "Neither";
                right = left;
                count = 0;
                while(right < queryIP.size() && queryIP[right] != '.' && right-left <= 3){
                    if(!isdigit(queryIP[right]))      return "Neither";
                    count = count*10 + (queryIP[right]-'0');
                    right++;
                }
                if((queryIP[left] == '0' && left+1 != right) || count > 255){
                    return "Neither";
                }                
                left = right+1;
            }
            if(queryIP.back() == '.')       return "Neither";
            return "IPv4";
        }  
        else if(TypeFlag == 6 && count == 7){
            // IPv6
            left = 0;
            while(left < queryIP.size()){
                if(queryIP[left] == ':')        return "Neither";
                right = left;
                while(right < queryIP.size() && queryIP[right] != ':' && right-left <= 4){
                    if(isalpha(queryIP[right]) && !(tolower(queryIP[right])>='a' && tolower(queryIP[right]) <= 'f'))      return "Neither";
                    right++;
                }
                if(right - left == 0 || right - left > 4)      return "Neither";
                left = right+1;
            }
            if(queryIP.back() == ':')       return "Neither";
            return "IPv6";
        }
        return "Neither";
    }
};