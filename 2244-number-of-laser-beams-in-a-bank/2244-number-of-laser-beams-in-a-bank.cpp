class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int size=bank[0].size();
        int m=bank.size();
        int ans=0;
        string zero;
        for(int i=0;i<size;i++){
            zero+='0';
        }
        int total=0;
        for(int i=0;i<m;i++){
              int curr=0;
               if(bank[i]==zero){
                continue;
               }
               for(int j=0;j<size;j++){
                if(bank[i][j]=='1')curr++;
               }
               cout<<i<<" "<<total<<" "<<curr<<endl;
               ans+=(total*curr);
               total=curr;
        }
        return ans;
    }
};