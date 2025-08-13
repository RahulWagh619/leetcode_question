// Last updated: 8/13/2025, 3:33:24 PM
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=(i*n)+j;
            }
        }
        int x=0;
        int y=0;
       for(int i=0;i<commands.size();i++){        
            if(commands[i]=="UP"){
                x--;
            }
            if(commands[i]=="DOWN"){
                x++;

            }
            if(commands[i]=="LEFT"){
                y--;

            }
            if(commands[i]=="RIGHT"){
              y++;
            }
       }
       return grid[x][y];  
    }
};