class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int start=1;
        int end=m*n;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int count=0;
            for(int i=1;i<=m;i++){
                count+=min(mid/i,n);
            }
            if(count>=k){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};