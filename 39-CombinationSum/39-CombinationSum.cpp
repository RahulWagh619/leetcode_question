// Last updated: 8/13/2025, 3:37:40 PM
class Solution {
public:
void helper(vector<vector<int>>&v,vector<int>&candidates,int i,int target,vector<int>&a){
    if(i==candidates.size()){
        if(target==0){
        v.push_back(a);
        }
        return;
    }
    if(candidates[i]<=target){
       a.push_back(candidates[i]);
       helper(v,candidates,i,target-candidates[i],a);
       a.pop_back();
    }
    helper(v,candidates,i+1,target,a);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>a;
        helper(v,candidates,0,target,a);
        return v;
        
    }
};