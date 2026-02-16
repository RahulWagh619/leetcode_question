class Solution {
public:
    int reverseBits(int n) {
        string s="";
        if(n==0){
            return 0;
        }
        int z=log2(n)+1;
        cout<<z<<endl;
        while(n!=0){
            if(n%2==0){
                s+='0';
            }
            else{
                s+='1';
            }
            n/=2;
        }
        for(int i=z;i<=31;i++){
            s+='0';
        }
        reverse(s.begin(),s.end());
        //  cout<<s<<endl;
        long long ans=0;
        for(int i=0;i<s.length();i++){
            ans+=(1LL<<i)*(s[i]-'0');
            // cout<<ans<<" "<<i<<endl;
        }
        return ans;
    }
};