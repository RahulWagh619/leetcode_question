// Last updated: 8/13/2025, 3:37:20 PM
class Solution {
public:
    int mySqrt(long long x) {
        if(x==0){
            return 0;
        }
        int start=1;
        int end=x;
        int ans=1;
        while(start<=end){
           int mid=start+(end-start)/2;
           long long sq = (long long)mid * mid;
           if(sq==x){
            return mid;
           }
           else if(sq<x){
            ans=mid;
            start=mid+1;
           }
           else{
            end=mid-1;
           }
        }
        return ans;
        
    }
};