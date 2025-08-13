// Last updated: 8/13/2025, 3:35:48 PM
class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        vector<int>b;
        unordered_map<int,int>mpp;
        for(int i=0;i<a.size();i++){
            mpp[a[i]]++;
        }
        for(int i=0;i<a.size();i++){
            if(mpp[a[i]]==1){
               b.push_back(a[i]);
            }
        }
        return b;
    }
};