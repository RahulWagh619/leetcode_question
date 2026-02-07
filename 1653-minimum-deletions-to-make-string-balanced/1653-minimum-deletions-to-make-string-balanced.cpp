class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int>pf(n);
        vector<int>sf(n);
        int countb=0;
        for(int i=0;i<n;i++){
            pf[i]=countb;
            if(s[i]=='b')countb++;
        }
        int counta=0;
         for(int i=n-1;i>=0;i--){
            sf[i]=counta;
            if(s[i]=='a')counta++;
        }
        int mini=n;
        for(int i=0;i<n;i++){
            mini=min(mini,pf[i]+sf[i]);
        }
        return mini;
    }
};