class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int i1=source[0];
        int j1=source[1];
        int i2=target[0];
        int j2=target[1];
        if((i1%2==0 && j1%2==0)||(i1%2==1 && j1%2==1)){
            if((i2%2==1 && j2%2==0) || (i2%2==0 && j2%2==1))return -1;
        }
        else {
            if((i2%2==1 && j2%2==1) || (i2%2==0 && j2%2==0))return -1;
        }
        int x=i1;
        int y=j1;
        while(x>=1 && y<=8){
            if(x==i2 && y==j2)return 1;
            x--;
            y++;
        }
        x=i1;
        y=j1;
        while(y<=8 && x<=8){
            if(x==i2 && y==j2)return 1;
            x++;
            y++;
        }
        x=i1;
        y=j1;
        while(y>=1 && x>=1){
            if(x==i2 && y==j2)return 1;
            x--;
            y--;
        }
        x=i1;
        y=j1;
        while(y>=1 && x<=8){
            if(x==i2 && y==j2)return 1;
            x++;
            y--;
        }
        return 2;

    }
};