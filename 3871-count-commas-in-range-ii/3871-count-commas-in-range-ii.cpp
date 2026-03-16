class Solution {
public:
    long long countCommas(long long n) {
        long long val=1000;
        long long count=0;
        while(n>=val){
           long long z=n-val;
           z++;
           count+=z;
           val*=1000;
        } 
        return count;
    }
};