/*
Author : Shreeraksha R Aithal
Problem name : Employee Importance
Problem link : https://leetcode.com/problems/employee-importance/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Hash Table
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int calculateImp(map<int, Employee*> mapping, Employee* emp){
        if(emp == nullptr)      return 0;
        int total = emp->importance;
        for(auto id : emp->subordinates){
            total += calculateImp(mapping, mapping[id]);
        }
        return total;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> mapping;
        for(auto itr : employees){
            mapping[itr->id] = itr;
        }
        return calculateImp(mapping, mapping[id]);
    }
};