// Last updated: 8/13/2025, 3:35:12 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int start = 0;
        int end = a.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid % 2 == 0) { // Even index
                if (mid == a.size() - 1 || a[mid] != a[mid + 1]) { // Ensure mid+1 is within bounds
                    if (mid == 0 || a[mid] != a[mid - 1]) {  
                        return a[mid]; // Found the single element
                    } 
                    end = mid - 2; // Move left
                } else {
                    start = mid + 2; // Move right
                }
            } 
            else { // Odd index
                if (a[mid] != a[mid - 1]) {  
                    if (mid == a.size() - 1 || (mid < a.size() - 1 && a[mid] != a[mid + 1])) {  
                        return a[mid]; // Found the single element
                    }
                    end = mid - 1; // Move left
                } else {
                    start = mid + 1; // Move right
                }
            }
        }
        
        return -1; // This should never be reached in a valid input case
    }
};
