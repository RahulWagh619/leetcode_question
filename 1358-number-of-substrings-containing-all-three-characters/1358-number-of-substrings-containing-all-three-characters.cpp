class Solution {
public:
bool check(map<char,int>mpp){
    if(mpp.find('a')==mpp.end())return false;
    if(mpp.find('b')==mpp.end())return false;
    if(mpp.find('c')==mpp.end())return false;
    return true;
}
    int numberOfSubstrings(string s) {
        int n=s.length();
        map<char,int>mpp;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            if(check(mpp)){
                ans+=n-i;
                while(j<n){
                    mpp[s[j]]--;
                    if(mpp[s[j]]==0){
                        mpp.erase(s[j]);
                    }
                    j++;
                    if(check(mpp)){
                        ans+=n-i;
                    }
                    else{
                        break;
                    }
                }
                // ans--;
            }
        }
        return ans;
    }
};