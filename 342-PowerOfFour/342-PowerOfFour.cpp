// Last updated: 8/15/2025, 3:20:21 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        if(n==1)return true;
        long double k=log10(n)/log10(4);
        if(k==ceil(k))return true;
        return false;
        
    }
};