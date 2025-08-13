// Last updated: 8/13/2025, 3:34:52 PM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int sum5=0;
        int sum10=0;
        for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
           sum5++;
        }
        else if(bills[i]==10){
           sum10++;
           sum5--;
        }
        else{
            if(sum10>0){
            sum10--;
            sum5--;
            }
            else{
                sum5--;
                sum5--;
                sum5--;
            }
         }
        if(sum10<0){
            return false;
        }
        if(sum5<0)return false;
        }
        return true;
    }
};