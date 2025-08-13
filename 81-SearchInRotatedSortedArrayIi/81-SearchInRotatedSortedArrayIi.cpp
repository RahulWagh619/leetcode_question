// Last updated: 8/13/2025, 3:37:12 PM
class Solution {
public:
    bool search(vector<int>& a, int target) {
        int start=0;
        int end=a.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(a[mid]==target){
                return true;
            }
            if(a[start]==a[mid] && a[mid]==a[end]){
                start++;
                end--;
                continue;
            }
             if (a[start] <= a[mid]) {
                if (target >= a[start] && target < a[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            if(a[mid]<=a[end]){
                if (target > a[mid] && target <=a[end])
                    start = mid + 1;
                else
                    end = mid - 1;

            }

           
        }
        return false;
    }
};