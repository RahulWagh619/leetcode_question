class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        map<int,int>mpp;
        for(int i=0;i<weight.size();i++){
            mpp[weight[i]]++;
        }
        if(mpp.size()==1){
            return 0;
        }
        // int mini=1;
        int count=0;
        int currmaxi=-1;
        for(int i=0;i<weight.size();i++){
            if(currmaxi==-1){
                currmaxi=weight[i];
            }
            else{
                if(currmaxi<=weight[i]){
                    currmaxi=weight[i];
                }
                else{
                    currmaxi=-1;
                    count++;
                }
            }
        }
        return count;


    }
};