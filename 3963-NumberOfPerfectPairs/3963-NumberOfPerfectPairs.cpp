// Last updated: 8/19/2025, 8:58:22 PM
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        vector<int>ans=nums;
        for(int i=0;i<ans.size();i++){
            ans[i]=abs(ans[i]);
        }
        sort(ans.begin(),ans.end());
        long long count=0;
        for(int i=0;i<ans.size()-1;i++){
            int idx=upper_bound(ans.begin()+i+1,ans.end(),2*ans[i])-(ans.begin()+i+1);
            count+=idx;
        }
        return count;
    }
};