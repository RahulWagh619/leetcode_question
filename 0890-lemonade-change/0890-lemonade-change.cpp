class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool ans=true;
        int val=0;
        int fiver=0;
        int tener=0;
        // int tweter=0;
        for(int i=0;i<bills.size();i++){
              if(bills[i]==5){
                fiver++;
              }
              else if(bills[i]==10 && fiver>0){
                tener++;
                fiver--;
              }
              else if(bills[i]==20 && (fiver>2||fiver>0 && tener>0)){
                 if(fiver>0 && tener>0){
                    fiver--;
                    tener--;
                 }
                 else{
                    fiver-=3;
                 }
                //  tweter++;
              }
              else{
                ans=false;
                break;
              }
        }
        return ans;
    }
};