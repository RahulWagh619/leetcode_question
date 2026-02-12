class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            map<char,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(auto &z:mpp){
                mini=min(mini,z.second);
                maxi=max(maxi,z.second);
            }
            if(mini==maxi){
                ans=max(ans,j-i+1);
            }
            }
        }
        return ans;
    }
};