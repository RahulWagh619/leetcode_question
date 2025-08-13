// Last updated: 8/13/2025, 3:37:43 PM
class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        int start=0;
        int end=a.size()-1;
        int mid;
        if(target>a[end]){
            return end+1;
        }
        else if(target<a[start]){
            return start;
        }
        while(start<=end){
            int mid=(start+end)/2;
            if(a[mid]==target){
                return mid;
            }
            if(a[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return end+1;
        
    }
};