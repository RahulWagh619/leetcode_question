class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>a;
        for(int i=n-1;i>=0;i--){
            vector<int>b;
            int x=i;
            int y=0;
            while(x<n && y<m){
                b.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(b.begin(),b.end());
            a.push_back(b);
        }
        for(int j=1;j<m;j++){
            vector<int>b;
            int x=0;
            int y=j;
            while(x<n && y<m){
                b.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(b.begin(),b.end());
            a.push_back(b);
        }
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
                int x=n-i-1;
                int y=0;
            for(int j=0;j<a[i].size();j++){
                ans[x][y]=a[i][j];
                x++;
                y++;
            }
        }
        for(int j=1;j<m;j++){
              int x=0;
              int y=j;
            int a_idx = n + j - 1; 
    
    // Check if the index is valid before accessing
    if (a_idx < a.size()) {
        for(int i=0; i<a[a_idx].size(); i++){
            ans[x][y] = a[a_idx][i];
            x++;
            y++;
        }
    }
           
        }
        return ans;
    }
};