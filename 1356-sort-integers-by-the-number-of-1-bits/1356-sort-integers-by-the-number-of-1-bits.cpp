class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<pair<int,int>>vp;
        for(int i=0;i<arr.size();i++){
            int val=__builtin_popcount(arr[i]);
            vp.push_back({val,i});
        }
        sort(vp.begin(),vp.end());
        vector<int>z;
        for(int i=0;i<arr.size();i++){
            z.push_back(arr[vp[i].second]);
        }
        return z;
    }
};