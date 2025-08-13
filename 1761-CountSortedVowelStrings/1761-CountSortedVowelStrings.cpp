// Last updated: 8/13/2025, 3:34:05 PM
class Solution {
public:
long long nCr(int n, int r) {
    long long res = 1;
    for(int i = 1; i <= r; ++i) {
        res *= (n - r + i);
        res /= i;
    }
    return res;
}
    int countVowelStrings(int n) {
        return nCr(n+4,4);
    }
};