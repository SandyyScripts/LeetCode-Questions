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
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans=0;
        for(auto ele:employees){
            if(ele->id==id){
                ans+=ele->importance;
                for(auto ids:ele->subordinates){
                    ans+=getImportance(employees,ids);
                }
            }
        }
        return ans;
    }
};