// Last updated: 8/13/2025, 3:33:42 PM
class Solution {
public:
    long long coloredCells(int n) {
        long long k=(long long)n*n;
        long long j=(long long)n-1;
        long long z=(long long)j*j;
        return k+z;
    }
};