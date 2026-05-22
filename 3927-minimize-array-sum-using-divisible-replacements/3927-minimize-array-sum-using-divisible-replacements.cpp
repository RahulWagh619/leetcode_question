class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            int best=nums[i];
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    int val1=j;
                    int val2=nums[i]/j;
                    if(st.count(val1)){
                        best=min(best,val1);
                    }
                    if(st.count(val2)){
                        best=min(best,val2);
                    }
                }
            }
            sum+=best;
        }
        return sum;
    }
};