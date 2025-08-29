class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long val=m/2;
            if(i & 1){
                ans+=val;
            }
            else{
                ans+=(m-val);
            }
        }
        return ans;
    }
};