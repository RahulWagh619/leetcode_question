class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0){
            return false;
        }
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int maxi=INT_MIN;
        for(auto &i:mpp){
            maxi=max(maxi,i.second);
        }
        int diff=(n/k);
        if(maxi>diff){
            return false;
        }
        return true;
    }
};