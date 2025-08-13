// Last updated: 8/13/2025, 3:34:08 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int miss=arr[mid]-(mid+1);
            if(miss>=k){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        // if(k==1){
        //     return start;
        // }
        // else return start+k;
        return start+k;
        
    }
};