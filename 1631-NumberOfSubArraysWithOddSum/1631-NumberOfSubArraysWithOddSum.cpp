// Last updated: 8/13/2025, 3:34:10 PM
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int count=0;
        const int mod=1e9+7;
        long long prefixsum=0;
        int oddc=0;
        int evenc=1;
        for(int i=0;i<arr.size();i++){
            prefixsum+=arr[i];
            if (prefixsum % 2 == 0) { 
                count = (count + oddc) % mod;
                evenc++;
            } else { 
                count = (count + evenc) % mod;
                oddc++;
            }
        }
        return  count;
    }
};