class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int l=0;
        map<char,int>mpp;
        for(int r=0;r<s.length();r++){
             mpp[s[r]]++;
             while(mpp[s[r]]>1){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
             }
             maxi=max(maxi,(r-l+1));
        }
        return maxi;
    }
};