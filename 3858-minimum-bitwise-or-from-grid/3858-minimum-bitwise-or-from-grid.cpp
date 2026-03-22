class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        for(int bit=31;bit>=0;bit--){
            vector<vector<int>>temp(n);
            bool val=true;
            for(int i=0;i<n;i++){
                bool yes=false;
                for(int j=0;j<grid[i].size();j++){
                    if(((grid[i][j] >> bit)& 1)==0){
                        yes=true;
                        temp[i].push_back(grid[i][j]);
                    }
                }
                if(!yes){
                    val=false;
                    break;
                }
            }
            if(!val){
                ans|=(1<<bit);
            }
            else{
                grid=temp;
            }
        }
        return ans;
    }
};