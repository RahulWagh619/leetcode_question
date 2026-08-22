class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long mul=1;
        int val=n;
        while(n>0){
            int dig=n%10;
            sum+=dig;
            mul*=dig;
            n/=10;
        }
        // cout<<sum<<" "<<mul<<endl;
        sum+=mul;
        // cout<<sum<<" "<<val<<endl;
        if(val%sum==0)return true;
        return false;
    }
};