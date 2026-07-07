class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.length();
        if(n==1){
            if(s1[0]=='1' && s2[0]=='0')return -1;
            if(s1==s2)return 0;
            else return 1;
        }
        int ans=0;
        for(int i=n-1;i>0;i--){
            if(s1[i]!=s2[i]){
                if(s1[i]=='0'){
                    s1[i]='1';
                    ans++;
                }
                else{
                    if(s1[i-1]==s2[i-1]){
                        ans+=2;
                        s1[i]=s2[i];
                    }
                    else if(s1[i-1]=='1'){
                        ans++;
                        s1[i]=s2[i];
                        s1[i-1]=s2[i-1];
                    }
                    else{
                        ans+=3;
                        s1[i]=s2[i];
                        s1[i-1]=s2[i-1];
                    }
                }
            }
        }
        if(s1[0]!=s2[0]){
            if(s1[0]=='0')ans++;
            else ans+=2;
        }
        return ans;
    }
};