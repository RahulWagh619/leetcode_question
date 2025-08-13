// Last updated: 8/13/2025, 3:35:46 PM
class Solution {
public:
    int hIndex(vector<int>& a) {
       int start=0;
       int end=a.size()-1;
    //   int ans=0;
       while(start<=end){
        int mid=start+(end-start)/2;
        int val=a.size()-mid;
        if(a[mid]>=val){
            end=mid-1;
        }
        else{
            start=mid+1;
        }

       }
       return a.size()-start;
    }
};