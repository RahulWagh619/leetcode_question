class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int c1=0;
        int c2=0;
        int n=moves.length();
        for(int i=0;i<n;i++){
                if(moves[i]=='L'){
                    c2--;
                    c1++;
                }
                else if(moves[i]=='R'){
                    c2++;
                    c1++;
                }
        }
        c2=abs(c2);
        int left=n-c1;
        int ans=left+c2;
        return ans;
    }
};