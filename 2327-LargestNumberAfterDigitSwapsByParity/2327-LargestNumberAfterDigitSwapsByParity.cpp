// Last updated: 8/13/2025, 3:33:48 PM
class Solution {
public:
    int largestInteger(int num) {
        string a = to_string(num);
        vector<int> odd, even;
        
        // Separate odd and even digits
        for (char c : a) {
            if ((c - '0') % 2 == 0) {
                even.push_back(c - '0');
            } else {
                odd.push_back(c - '0');
            }
        }
        
        // Sort both in descending order
        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());
        
        int oddIdx = 0, evenIdx = 0;
        
        // Place the largest possible digits at respective positions
        for (int i = 0; i < a.size(); i++) {
            if ((a[i] - '0') % 2 == 0) {
                a[i] = even[evenIdx++] + '0';
            } else {
                a[i] = odd[oddIdx++] + '0';
            }
        }
        
        // Convert the modified string back to integer
        return stoi(a);
    }
};
