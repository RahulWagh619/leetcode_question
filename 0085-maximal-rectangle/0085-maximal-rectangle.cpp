class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int v = matrix.size();
        int m = matrix[0].size();
        vector<int> a(m, 0);
        int ans = 0;
        
        for(int i = 0; i < v; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    a[j]++;
                }
                else{
                    a[j] = 0;  // Reset on '0'
                }
            }
            
            ans = max(ans, largestRectangleArea(a));
        }
        return ans;
    }
    
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr(n), nsl(n);
        stack<pair<int,int>> st;
        
        // NSL
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] <= st.top().first){
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top().second;
            st.push({heights[i], i});
        }
        
        while(!st.empty()) st.pop();
        
        // NSR
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[i] <= st.top().first){
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top().second;
            st.push({heights[i], i});
        }
        
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = nsr[i] - nsl[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
