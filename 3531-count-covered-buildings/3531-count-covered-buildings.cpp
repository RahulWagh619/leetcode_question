class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int count=0;
        map<int,vector<int>>mppx;
        map<int,vector<int>>mppy;
        int size=buildings.size();
        for(int i=0;i<size;i++){
            int x=buildings[i][0];
            int y=buildings[i][1];
            mppx[x].push_back(y);
            mppy[y].push_back(x);
        }
        for(auto &i:mppx){
            sort(i.second.begin(),i.second.end());
        }
        for(auto &i:mppy){
            sort(i.second.begin(),i.second.end());
        }
        for(int i=0;i<size;i++){
            int x=buildings[i][0];
            int y=buildings[i][1];
            if(mppx[x].size()>2 && mppy[y].size()>2){
                if(mppx[x][0]<y&& mppx[x][mppx[x].size()-1]>y){
                    if(mppy[y][0]<x && mppy[y][mppy[y].size()-1]>x){

                count++;
                    }

                }
            }
        }
        return count;
    }
};