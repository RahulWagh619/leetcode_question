class Solution {
public:
    int mirrorDistance(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int z=stoi(s);
        int val=abs(z-n);
        return val;
    }
};