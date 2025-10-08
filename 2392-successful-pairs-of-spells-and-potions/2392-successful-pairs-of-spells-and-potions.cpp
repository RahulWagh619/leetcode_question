class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int m=potions.size();
        int n=spells.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            long long val=(success+spells[i]-1)/spells[i];
            ans[i] = m - (lower_bound(potions.begin(), potions.end(), val) - potions.begin());
        }
        return ans;
    }
};