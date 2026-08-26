class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        int count=0;
        string ans="";
        int mini=INT_MAX;
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            while(j<=i && count==k){
                int len=i-j+1;
                if(mini>=len){
                    string z=s.substr(j,len);
                    // cout<<z<<endl;
                    if(mini==INT_MAX){
                        ans=z;
                    }
                    else{
                        if(mini==len){
                            if(ans>z){
                                ans=z;
                            }
                        }
                        else{
                            ans=z;
                        }
                    }
                    mini=len;
                }
                if(s[j]=='1')count--;
                j++;
            }
        }
        return ans;
    }
};