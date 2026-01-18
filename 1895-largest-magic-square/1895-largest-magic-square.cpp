class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans=1;
        int n=grid.size();
        int m=grid[0].size();
        int mini=min(n,m);
        bool found=false;
        for(int k=mini;k>=2;k--){
            int col=m-k;
            int row=n-k;

            for(int z=0;z<=row;z++){
                for(int v=0;v<=col;v++){
                    int sum=0;
                 for(int j=0+v;j<k+v;j++){
                    sum+=grid[z][j];
                  }
                  bool istrue=true;
                  for(int i=0+z;i<k+z;i++){
                    int f=0;
                    for(int j=0+v;j<k+v;j++){
                        f+=grid[i][j];
                    }
                    if(f!=sum){
                        istrue=false;
                        break;
                    }
                  }
                  if(!istrue){
                    continue;
                  }
                   for(int j=0+v;j<k+v;j++){
                    int f=0;
                    for(int i=0+z;i<k+z;i++){
                        f+=grid[i][j];
                    }
                    if(f!=sum){
                        istrue=false;
                        break;
                    }
                  }
                   if(!istrue){
                    continue;
                  }
                 long long d1 = 0;
                    for (int i = 0; i < k; i++) {
                        d1 += grid[z + i][v + i];
                    }
                    if (d1 != sum) continue;

                    long long d2 = 0;
                    for (int i = 0; i < k; i++) {
                        d2 += grid[z + i][v + k - 1 -i]; 
                    }
                    if (d2 != sum) continue;
                  if(istrue){
                    return k;
                  }
                }
            }
        }
        return ans;
    }
};