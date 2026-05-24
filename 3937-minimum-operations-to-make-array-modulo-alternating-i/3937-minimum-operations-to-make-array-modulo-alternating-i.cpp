class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
            int sum=0;
                if(i==j){
                    continue;
                }
                int c1=0;
                int c2=0;
                for(int z=0;z<n;z++){
                    int val=nums[z]%k;
                   if(z%2==0){
                     if(val!=i){
                        c1+=min(abs(val-i),k-abs(val-i));
                     }
                   } 
                   else{
                      if(val!=j){
                        c2+=min(abs(val-j),k-abs(val-j));
                     }
                   }  
                }
              sum=c1+c2;
            ans=min(ans,sum);
            }
        }
        return ans;
    }
};