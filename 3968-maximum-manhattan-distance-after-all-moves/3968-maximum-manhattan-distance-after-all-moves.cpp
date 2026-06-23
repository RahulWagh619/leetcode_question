class Solution {
public:
    int maxDistance(string moves) {
        int maxi1=0;
        int maxi2=0;
        int n=moves.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U'){
                maxi1++;
            }
            else if(moves[i]=='D'){
                maxi1--;
            }
            else if(moves[i]=='L'){
                maxi2--;
            }
            else if(moves[i]=='R'){
                maxi2++;
            }
            else{
                count++;
            }
        }
        maxi1=abs(maxi1);
        maxi2=abs(maxi2);
        return count+maxi1+maxi2;

    }
};