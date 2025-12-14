class Solution {
public:
int mod=1e9+7;
    int numberOfWays(string corridor) {
        int count=0;
        int n=corridor.length();
        vector<int>index;
        int val=-1;
        // int two=2;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                count++;
                if(count%2==0){
                   val=i;
                //    two+=2;
                }
                if(count%2==1 && count>2){
                    // if(count==two-1){
                    int v=i-val;
                    index.push_back(v);
                    // }
                }
            }
        }
        if(count & 1||count==0){
            return 0;
        }
        if(index.size()==0){
            return 1;
        }
        long long ans=index[0];
        for(int i=1;i<index.size();i++){
            ans=(ans*index[i])%mod;
        }
        return ans;
    }
};