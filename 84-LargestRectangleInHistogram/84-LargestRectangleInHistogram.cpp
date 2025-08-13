// Last updated: 8/13/2025, 3:37:10 PM
class Solution {
public:
    vector<int> next(vector<int>& a) {
        stack<int> st;
        vector<int> v(a.size());
        st.push(a.size()); 
        for (int i = a.size() - 1; i >= 0; i--) {
            while (st.top() != a.size() && a[i] <= a[st.top()]) {
                st.pop();
            }
            v[i] = (st.top() == a.size()) ? a.size() : st.top();
            st.push(i); 
        }
        
        return v;
    }

    vector<int> prev(vector<int>& a) {
        stack<int> st;
        vector<int> v(a.size());
        st.push(-1); 
        for (int i = 0; i < a.size(); i++) {
            while (st.top() != -1 && a[i] <= a[st.top()]) {
                st.pop();
            }
            v[i] = st.top();
            st.push(i); 
        }
        
        return v;
    }

    int largestRectangleArea(vector<int>& a) {
        vector<int> value1 = next(a);
        vector<int> value2 = prev(a);
        int maxi = INT_MIN;
        
        for (int i = 0; i < a.size(); i++) {
            int width = value1[i] - value2[i] - 1;
            int area = width * a[i];
            maxi = max(maxi, area);
        }
        
        return maxi;
    }
};
