// Last updated: 8/13/2025, 3:34:47 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int start=1;
        int end=*max_element(a.begin(),a.end());
        int mini=end;
        while(start<=end){
            int mid=(start+end)/2;
            long long time=0;
            for(int i=0;i<a.size();i++){
            //  if(mid<=a[i]){
              time+=ceil((double)a[i]/mid);
            //  }
            }
            if(time<=h){
              mini=min(mini,mid);
              end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return mini;
    }
};