class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ans=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pf(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=mat[i][j];
               // Add Top
                if(i > 0) sum += pf[i-1][j];
                // Add Left
                if(j > 0) sum += pf[i][j-1];
                // Subtract Overlap (Top-Left)
                if(i > 0 && j > 0) sum -= pf[i-1][j-1];
                pf[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<min(m-j,n-i);k++){
                    int r2=i+k;
                    int c2=j+k;
                    int val=pf[r2][c2];
                   if(i > 0) val -= pf[i-1][c2];
                    
                    // Subtract Left Strip (if we are not at col 0)
                    if(j > 0) val -= pf[r2][j-1];
                    
                    // Add back Top-Left Overlap (if we are not at row 0 AND col 0)
                    if(i > 0 && j > 0) val += pf[i-1][j-1];
                    if(val<=threshold){
                        ans=max(ans,k+1);
                    }
                    else{
                        break;
                    }
                }
            
            }
        }
        return ans;
    }
};