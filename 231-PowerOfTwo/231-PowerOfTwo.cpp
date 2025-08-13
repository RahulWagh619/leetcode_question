// Last updated: 8/13/2025, 3:36:00 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        if((n & n-1)==0) return true;
        return false;
    }
};