class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1)return s;
        long long ans=s+m;
        int half=n/2;
        return ans+(1LL*(half-1)*(m-1));
    }
};