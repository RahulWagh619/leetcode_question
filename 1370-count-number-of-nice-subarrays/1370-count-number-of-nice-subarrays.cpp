class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>count(n+1);
        count[0]=0;
        for(int i=1;i<=n;i++){
            if(nums[i-1] & 1){
                count[i]=count[i-1]+1;
            }
            else{
                count[i]=count[i-1];
            }
        }
        if(count[n]<k){
            return 0;
        }
        map<int,int>mpp;
        int ans=0;
        mpp[0]=1;
        for(int i=1;i<=n;i++){
            int l=count[i]-k;
            if(mpp.find(l)!=mpp.end()){
               ans+=mpp[l];
            }
            mpp[count[i]]++;
        }
        return ans;
    }
};