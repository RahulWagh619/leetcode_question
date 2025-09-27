class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mpp;
        for(int i=0;i<t.length();i++){
            mpp[t[i]]++;
        }
        map<char,int>freq;
        string z="";
        int total=mpp.size();
        int curr=0;
        int mini=INT_MAX;
        int x=-1;
        int y=-1;
        int l=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]]++;
            if(mpp.count(s[r]) && freq[s[r]]==mpp[s[r]]){
                curr++;
            }
            // if(total==curr){
            //     if((r-l+1)<mini){
            //         mini=min(mini,r-l+1);
            //         x=l;
            //         y=r;
            //         z=s.substr(l,r-l+1);
            //     }
                while(total==curr){
                     if((r-l+1)<mini){
                    mini=min(mini,r-l+1);
                    // z=s.substr(l,r-l+1);
                    x=l;
                    y=r;
                }
                    freq[s[l]]--;
                    if(freq[s[l]]==0){
                        freq.erase(s[l]);
                    }
                    if(mpp.count(s[l]) && freq[s[l]]<mpp[s[l]]){
                        curr--;
                    }
                    l++;
                }
            // }
        }
        if(x==-1||y==-1){
           return z;
        }
        z=s.substr(x,y-x+1);
        return z;
        
    }
};