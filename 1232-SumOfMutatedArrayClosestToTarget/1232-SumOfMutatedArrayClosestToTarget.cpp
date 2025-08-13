// Last updated: 8/13/2025, 3:34:23 PM
class Solution {
public:
int finalsum(vector<int>&a,int k){
      int sum1=0;
      for(int i=0;i<a.size();i++){
          if(a[i]>k){
            sum1+=k;
          }
          else{
            sum1+=a[i];
          }
      }
      return sum1;

}
    int findBestValue(vector<int>& a, int target) {
        int sum=0;
        int n=a.size();
        sort(a.begin(),a.end());
        int start=0;
        int end=a[n-1];
        int ans=-1;
        int mini=INT_MAX;
        while(start<=end){
            int mid = start + (end - start) / 2;;
            int val=finalsum(a,mid);
            int diff=abs(target-val);
            if (diff < mini) {
                mini = diff;
                ans = mid;
            } else if (diff == mini) {
                ans = min(ans, mid);
            }
            if(val>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};