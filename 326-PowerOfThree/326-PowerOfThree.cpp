// Last updated: 8/13/2025, 3:35:37 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        if(n==1)return true;
        long double x=log10(n) / log10(3);;
        if(x==ceil(x)){
            return true;
        }
        return false;
    }
};