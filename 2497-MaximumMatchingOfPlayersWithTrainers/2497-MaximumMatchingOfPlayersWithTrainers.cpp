// Last updated: 8/13/2025, 3:33:45 PM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int j=0;
        int count=0;
         int n = players.size(), m = trainers.size();
        for(int i=0;i<n;i++){
            if(j==m){
                continue;
            }
            else{
                while( j<m && players[i]>trainers[j]){
                    j++;
                }
                if(j<m&& players[i]<=trainers[j]){
                    j++;
                    count++;
                }
            }
        }
        return count;
        
    }
};