// Last updated: 8/13/2025, 3:37:39 PM
class Solution {
public:
void printsubsequence(int i,int target,vector<int>&a,vector<int>&b,vector<vector<int>>&ans){
    if(i>=a.size()){
        if(target==0){
            ans.push_back(b);
        }
        return;
    }
    if(a[i]<=target){
        b.push_back(a[i]);
        printsubsequence(i+1,target-a[i],a,b,ans);
        b.pop_back();
    }
    while(i+1<a.size()&& a[i]==a[i+1]){
        i++;
    }
   printsubsequence(i+1,target,a,b,ans);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int i=0;
        sort(candidates.begin(),candidates.end());
        vector<int>b;
        vector<vector<int>>ans;
        printsubsequence(i,target,candidates,b,ans);
        return ans;
    }
};