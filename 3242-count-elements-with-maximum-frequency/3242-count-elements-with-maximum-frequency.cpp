class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int maxi=INT_MIN;
        for(auto &i:mpp){
            maxi=max(maxi,i.second);
        }
        int sum=0;
        for(auto &i:mpp){
            if(i.second==maxi){
                sum++;
            }
        }
        return sum*maxi;
    }
};