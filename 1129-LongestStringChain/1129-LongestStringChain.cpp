// Last updated: 8/13/2025, 3:34:28 PM
class Solution {
public:

bool check(string s, string k) {
    if (s.length() != k.length() + 1) return false;
    int count = 0;
    int i = 0, j = 0;
    while (i < s.length() && j < k.length()) {
        if (s[i] == k[j]) {
            i++; j++;
        } else {
            count++;
            i++;
        }
    }
    //  if (i < s.length()) count++;
    return count<=1;
}

    int longestStrChain(vector<string>& words) {
         int n=words.size();
         sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
});
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i],words[prev])){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
    }
};