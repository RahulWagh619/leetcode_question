// Last updated: 8/13/2025, 3:36:44 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            ans=max(ans,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return ans;
    }
};