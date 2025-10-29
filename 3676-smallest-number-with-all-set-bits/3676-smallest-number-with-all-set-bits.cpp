class Solution {
public:
    int smallestNumber(int n) {
        long long val=1;
        while(val<=n){
            val*=2;
        }
       return val-1;
    }
};