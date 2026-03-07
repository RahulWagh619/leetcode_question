class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi=1;
        int n=s.length();
        map<char,int>mpp;
        int l=0;
        int maxf=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            maxf=max(maxf,mpp[s[i]]);
            while((i-l+1)-maxf>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            maxi=max(i-l+1,maxi);           
        }
        return maxi;
    }
};