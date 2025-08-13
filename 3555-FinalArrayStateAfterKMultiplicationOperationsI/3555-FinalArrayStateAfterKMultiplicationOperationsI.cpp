// Last updated: 8/13/2025, 3:33:30 PM
class Solution {
public:
    vector<int> getFinalState(vector<int>& a, int k, int multiplier) {
        while(k!=0){
            int mini=INT_MAX;
            int store=0;
            for(int i=0;i<a.size();i++){
                if(a[i]<mini){
                    mini=a[i];
                    store=i;
                }
            }
            a[store]=a[store]*multiplier;
            k--;
        }
    return a;    
    }
};