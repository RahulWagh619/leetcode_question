// Last updated: 8/13/2025, 3:33:34 PM
class Solution {
public:
    bool canAliceWin(vector<int>& a) {
        int sum1=0;
        int sum2=0;
        for(int i=0;i<a.size();i++){
           if(a[i]<10){
            sum1+=a[i];
           }
           else{
            sum2+=a[i];
           }
        }
        if(sum1==sum2){
            return false;
        }
        else{
            return true;
        }
    }
};