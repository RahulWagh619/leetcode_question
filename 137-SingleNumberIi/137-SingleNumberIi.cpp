// Last updated: 8/13/2025, 3:36:30 PM
class Solution {
public:
    int singleNumber(vector<int>& a) {
        unordered_map<int,int>mpp;
        for(int i=0;i<a.size();i++){
            mpp[a[i]]++;
        }
        int store;
        for(int i=0;i<a.size();i++){
            if(mpp[a[i]]==1){
                store=a[i];
            }
        }
        return store;
        
    }
};