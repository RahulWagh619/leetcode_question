// Last updated: 8/13/2025, 3:34:12 PM
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        // sort(target.begin(),target.end());
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        // bool change=true;
        for(int i=0;i<target.size();i++){
            mpp1[target[i]]++;
            mpp2[arr[i]]++;
        }
       
        return mpp1==mpp2;
    }
};