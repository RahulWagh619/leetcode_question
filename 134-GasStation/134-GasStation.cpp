// Last updated: 8/13/2025, 3:36:33 PM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int def=0;
        int bal=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            bal+=gas[i]-cost[i];
            if(bal<0){
                def+=bal;
                start=i+1;
                bal=0;
            }
        }
        if(bal+def>=0){
            return start;

        }
        else{
            return -1;
        }
        
    }
};